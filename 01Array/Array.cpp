//
// Created by tracy on 2021/3/11.
//

#include "Array.h"

//初始化数组
Array * initArray(int size)
{
    if (size <= 0)
    {
        perror("Init Array Failed Size <= 0 !!!");
        return NULL;
    }
    else
    {
        Array *pArray = (Array *) calloc(1, sizeof(Array));
        if (!pArray)
        {
            perror("calloc(1, sizeof(Array)) Failed");
            return NULL;
        }
        pArray->data = (void**)calloc(size, sizeof(void *));
        if (!pArray->data)
        {
            perror("calloc(cap, sizeof(void *)) Failed");
            return NULL;
        }

        pArray->size = size;
        pArray->len = 0;
        return pArray;
    }
}

//指定位置插入数据
int insertArrayByPos(Array *pArr, int pos, void *data)
{
    if (!pArr)
    {
        return RET_FAIL;
    }

    if (pos > pArr->len || pos < 0)
    {
        return RET_FAIL;
    }

    //数组需要扩容
    if (pArr->len == pArr->size)
    {
        int newSize = 2 * pArr->size;
        void **pNewAddr = (void **)calloc(newSize, sizeof(void *));
        if (!pNewAddr)
        {
            return RET_FAIL;
        }

        memcpy(pNewAddr, pArr->data, sizeof(void *) * pArr->size);
        free(pArr->data);
        pArr->data = pNewAddr;
        pArr->size = newSize;
    }

    //插入数据
    int loop = pArr->len;
    while (pos < loop)
    {
        pArr->data[loop] = pArr->data[loop - 1];
        --loop;
    }
    pArr->data[pos] = data;
    ++pArr->len;
    return RET_OK;
}

//遍历数组
void foreachArray(Array *pArr, void(*print)(void *date))
{
    if (!pArr)
    {
        return;
    }

    for (int i = 0; i < pArr->len; ++i)
    {
        print(pArr->data[i]);
    }
    printf("\n");
}

//指定位置删除数据
int deleteArrayByPos(Array *pArr, int pos)
{
    if (!pArr || pos < 0 || pos >= pArr->len)
    {
        return RET_FAIL;
    }

    for (int i = pos; i < pArr->len - 1; ++i)
    {
        pArr->data[i] = pArr->data[i + 1];
    }

    --pArr->len;
    return RET_OK;
}

//获取数组长度
int getArrayLength(Array *pArr)
{
    if (!pArr)
    {
        return RET_FAIL;
    }
    return pArr->len;
}

//获取数组容量
int getArraySize(Array *pArr)
{
    if (!pArr)
    {
        return RET_FAIL;
    }
    return pArr->size;
}

//销毁数组
void destoryArray(Array *pArr, void (*Free)(void *data))
{
    if (!pArr)
    {
        return;
    }

    //如果是自己申请内存的，需要实现 Free
    for (int i = 0; i < pArr->len; ++i)
    {
        if (NULL != Free)
        {
            Free(pArr->data[i]);
        }
    }

    free(pArr->data);
    pArr->data = NULL;
    free(pArr);
    pArr = NULL;
}