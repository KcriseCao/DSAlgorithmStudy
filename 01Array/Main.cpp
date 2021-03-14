//
// Created by tracy on 2021/3/11.
//
#include "Array.h"
#include "StaticArray.h"

void PRINT(void *data)
{
    int *p = (int *)data;
    printf("%d ", *p);
}

void testDynamicArray()
{
    Array *pArr = initArray(10);
    for (int i = 0; i < 20; ++i)
    {
        int *pInt = new int(i);
        insertArrayByPos(pArr, i, pInt);
    }

    foreachArray(pArr, PRINT);

    deleteArrayByPos(pArr, 18);

    foreachArray(pArr, [](void *data) { int *p = (int *)data;printf("%d ", *p);} );

    destoryArray(pArr,[](void *data) { int *p = (int *)data; free(p); p = NULL;});
}

void testStaticArray()
{
    int ret = -1;
    ARRAY *pArray = initStaticArray(10);
    for (int i = 0; i < 10; ++i)
    {
        int *pInt = new int(i);
        ret = insertStaticArrayByPos(pArray, i, pInt);
        if (ret == RET_FAIL)
        {
            printf("data[%d] pos[%d] insert failed\n", i, i);
        }
    }

    foreachStaticArray(pArray, PRINT);
    int pos = 10;
    ret = deleteStaticArrayByPos(pArray, pos);
    if (ret == RET_FAIL)
    {
        printf("pos[%d] delete failed\n", pos);
    }
    foreachStaticArray(pArray, PRINT);

    pos = 8;
    ret = deleteStaticArrayByPos(pArray, pos);
    if (ret == RET_FAIL)
    {
        printf("pos[%d] delete failed\n", pos);
    }
    foreachStaticArray(pArray, [](void *data){int *p = (int *)data;printf("%d ", *p);});

    ret = destroyStaticArray(pArray, [](void *data){int *p = (int *)data;free(p);p = NULL;});
    ret == RET_OK? printf("Destroy StaticArray Success\n") : printf("Destroy StaticArray Failed\n");
}

bool COMPARE(void *data1, void *data2)
{
    int *pData1 = (int *)data1;
    int *pData2 = (int *)data2;
    return *pData1 > *pData2;
}

void merger2OrderArray(Array *pArr1, Array *pArr2, bool(*COMPARE)(void *data1, void *data2))
{
    if (NULL == pArr1 || NULL == pArr2)
    {
        return;
    }
    int j = 0;
    for (int i = 0; i < pArr1->len; ++i)
    {
        if (pArr2->len == j)
        {
            break;
        }

        if (COMPARE(pArr1->data[i], pArr2->data[j]))
        {
            insertArrayByPos(pArr1, i, pArr2->data[j]);
            ++j;
        }
    }
}

void testMerger()
{
    Array *pArr1 = initArray(10);
    Array *pArr2 = initArray(20);
    for (int i = 0; i < 10; ++i)
    {
        int *pInt = new int(i * 3);
        insertArrayByPos(pArr1, i, pInt);
    }
    for (int i = 0; i < 20; ++i)
    {
        int *pInt = new int(i * 2);
        insertArrayByPos(pArr2, i, pInt);
    }

    foreachArray(pArr1, PRINT);
    foreachArray(pArr2, PRINT);

    merger2OrderArray(pArr1, pArr2, COMPARE);
    foreachArray(pArr1, PRINT);
    foreachArray(pArr2, PRINT);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int lastest = m + n - 1;
    int i = m - 1;
    int j = n - 1;

    while (i >= 0 && j >= 0)
    {
        nums1[lastest--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
    while(j >= 0)
    {
        nums1[lastest--] = nums2[j--];
    }
}

int main(int argc, char **argv)
{
    //测试动态数组
    //testDynamicArray();

    //测试静态数组（定长）
    //testStaticArray();

    testMerger();

    return 0;
}
