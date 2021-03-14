/***********************************************************                                          *
* Time: 2021/3/14                                           
* Author: Kcrise                                          
***********************************************************/

#include "StaticArray.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//初始化固定长度的数组
ARRAY * initStaticArray(const int size)
{
    if (size <= 0)
    {
        return NULL;
    }
    ARRAY *pArray = (ARRAY *)calloc(1, sizeof(ARRAY));
    if (NULL == pArray)
    {
        return NULL;
    }

    pArray->pData = (void **)calloc(size, sizeof(void *));
    if (NULL == pArray->pData)
    {
        free(pArray);
        pArray = NULL;
        return NULL;
    }
    pArray->size = size;
    pArray->len = 0;
    return pArray;
}

RET insertStaticArrayByPos(ARRAY *pArray, const int pos, void *data)
{
    if (NULL == pArray)
    {
        return RET_FAIL;
    }

    if (pos < 0 || pos >= pArray->size)
    {
        return RET_FAIL;
    }

    if (isFull(pArray))
    {
        return RET_FAIL;
    }

    for (int i = pArray->len; i > pos; --i)
    {
        pArray->pData[i] = pArray->pData[i-1];
    }
    pArray->pData[pos] = data;
    ++pArray->len;
    return RET_OK;
}

//数组是否已满
bool isFull(ARRAY * pArray)
{
    if (NULL == pArray)
    {
        return true;
    }

    return (getStaticArrayLen(pArray) == getStaticArraySize(pArray));
}

//获取数据的长度
int getStaticArrayLen(ARRAY *pArray)
{
    if (NULL == pArray)
    {
        return -1;
    }

    return pArray->len;
}

//获取数据的容量
int getStaticArraySize(ARRAY *pArray)
{
    if (NULL == pArray)
    {
        return -1;
    }

    return pArray->size;
}

//指定位置删除数据
RET deleteStaticArrayByPos(ARRAY *pArray, const int pos)
{
    if (NULL == pArray)
    {
        return RET_FAIL;
    }

    if (pos < 0 || pos >= pArray->len)
    {
        return RET_FAIL;
    }

    for (int i = pos; i < pArray->len; ++i)
    {
        pArray->pData[i] = pArray->pData[i+1];
    }
    --pArray->len;
    return RET_OK;
}

//销毁数据
RET destroyStaticArray(ARRAY *pArray, void (*FREE)(void *data) = NULL)
{
    if (NULL == pArray)
    {
        return RET_FAIL;
    }

    if (FREE != NULL)
    {
        for (int i = 0; i < pArray->len; ++i)
        {
            FREE(pArray->pData[i]);
        }
    }

    free(pArray->pData);
    pArray->pData = NULL;
    free(pArray);
    pArray = NULL;
    return RET_OK;
}

//遍历数组
void foreachStaticArray(ARRAY *pArray, void (*PRINT)(void *data))
{
    if (NULL == pArray)
    {
        return;
    }

    for (int i = 0; i < pArray->len; ++i)
    {
        PRINT(pArray->pData[i]);
    }
    printf("\n");
}

