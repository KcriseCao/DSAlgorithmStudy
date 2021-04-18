/***********************************************************                                          *
* Time: 2021/3/27                                           
* Author: Kcrise                                          
***********************************************************/

#include "ArrayQueue.h"
#include "LinkedQueue.h"
#include "CircleQueue.h"

void testArrayQueue()
{
    ArrayQueue *pQueue = init_Array_Queue(2);
    if (!pQueue)
    {
        return;
    }
    for (int i = 1; i < 11; ++i)
    {
        int *p = malloc(sizeof(int));
        *p = i;
        push_ArrayQueue(pQueue, p);
    }

    void *p = front_Array_Queue(pQueue);
    printf("%d\n", *(int*)front_Array_Queue(pQueue));
    if (p)
    {
        free(p);
    }
    pop_Array_Queue(pQueue);

    void *p1 = back_Array_Queue(pQueue);
    printf("%d\n", *(int*)p1);

    for (int i = 0; i < pQueue->m_iLen; ++i)
    {
        printf("%d ", *(int*)pQueue->m_pAddr[i]);
    }
    printf("\n");

    while (size_Array_Queue(pQueue))
    {
        void *p = front_Array_Queue(pQueue);
        pop_Array_Queue(pQueue);
        free(p);
    }

    printf("Len = %d\n", size_Array_Queue(pQueue));
    destroy_Linked_Queue(pQueue);
}

void testLinkedQueue()
{
    LinkedQueue *pQueue = init_Linked_Queue();
    for (int i = 1; i < 11; ++i)
    {
        int *p = malloc(sizeof(int));
        *p = i;
        push_Linked_Queue(pQueue, p);
    }

    void *p = front_Linked_Queue(pQueue);
    printf("%d\n", *(int *)p);
    pop_Linked_Queue(pQueue);
    free(p);

    while (size_Linked_Queue(pQueue))
    {
        void *p = front_Linked_Queue(pQueue);
        printf("%d ", *(int *)p);
        pop_Linked_Queue(pQueue);
        free(p);
    }
    printf("\n");
}

void testCircleQueue()
{
    CQueue pQueue = init_CircleQueue(10);
    if (!pQueue)
    {
        return;
    }

    int a[20] = { 0 };
    for (int i = 0; i < 20; ++i)
    {
        a[i] = i + 1;
        push_CircleQueue(pQueue, a + i);
    }

    pop_CircleQueue(pQueue);
    push_CircleQueue(pQueue, &a[9]);

    printf("size = %d\n", size_CircleQueue(pQueue));
    while (RET_FAIL == isEmpty_CircleQueue(pQueue))
    {
        printf("%d ", *(int *)front_CircleQueue(pQueue));
        printf("size = %d\n", size_CircleQueue(pQueue));
        pop_CircleQueue(pQueue);
    }
    printf("\n");

    destroy_CircleQueue(pQueue);
}

int main(int argc, char *argv[])
{
    //testArrayQueue();

    //testLinkedQueue();

    testCircleQueue();

    return 0;
}