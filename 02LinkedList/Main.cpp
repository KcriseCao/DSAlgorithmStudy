/***********************************************************                                          *
* Time: 2021/3/16                                           
* Author: Kcrise                                          
***********************************************************/

#include "LinkedList.h"

void print(void *val)
{
    if (NULL == val)
    {
        return;
    }

    int data = *(int*)val;
    printf("%d ", data);
}

void Free(void *data)
{
    if (NULL != data)
    {
        free(data);
		data = NULL;
    }
}

void testLinkedList()
{
    List pList = initLinkedList();

    for(int i = 0; i < 10; ++i)
    {
        int *pVal = new int (i);
        pushBack(pList, pVal);
    }
    foreachLinkedList(pList, print);

    for(int i = 0; i < 10; ++i)
    {
        int *pVal = new int(2 * i);
        pushBack(pList, pVal);
    }
    foreachLinkedList(pList, print);

    reverseLinkedList(pList);
    foreachLinkedList(pList, print);

    int *pVal = new int(10);
    insertListByPos(pList, pList->len, pVal);
    foreachLinkedList(pList, print);

    pVal = new int(200);
    insertListByPos(pList, pList->len, pVal);
    foreachLinkedList(pList, print);

    popFront(pList, Free);
    foreachLinkedList(pList, print);

    popBack(pList, Free);
    foreachLinkedList(pList, print);

    clearLinkedList(pList, Free);
    printf("==================================\n");

    foreachLinkedList(pList, print);
    printf("==================================\n");

    destroyLinkedList(pList, Free);
    printf("==================================\n");
}


int main(int argc, char* argv[])
{
    testLinkedList();

    return 0;
}

