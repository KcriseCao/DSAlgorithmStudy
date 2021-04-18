/***********************************************************                                          *
* Time: 2021/4/17                                           
* Author: Kcrise                                          
***********************************************************/

#include "CircleQueue.h"


//初始化循环队列
CQueue init_CircleQueue(int capacity)
{
    if (capacity <= 0)
    {
        printf("The Capacity Of The Init Circle Queue Is Zero\n");
        return NULL;
    }

    CircleQueue *pQueue = (CircleQueue *) calloc(1, sizeof(CircleQueue));
    if (NULL == pQueue)
    {
        printf("Failed To Allocate CircleQueue Address\n");
        return NULL;
    }

    pQueue->m_pAddr = (void **) calloc(capacity, sizeof(void *));
    if (NULL == pQueue->m_pAddr)
    {
        printf("Failed To Allocate CircleQueue's Data Address\n");
        free(pQueue);
        pQueue = NULL;
        return NULL;
    }

    pQueue->m_iCapacity = capacity;
    pQueue->m_iHead = 0;
    pQueue->m_iTail = 0;

    return pQueue;
}

//销毁循环队列
void destroy_CircleQueue(CQueue queue)
{
    if (NULL == queue)
    {
        return;
    }

    CircleQueue *pQueue = (CircleQueue *)queue;
    if (pQueue->m_pAddr != NULL)
    {
        free(pQueue->m_pAddr);
        pQueue->m_pAddr = NULL;
    }

    free(pQueue);
    pQueue = NULL;
}

//入队列
void push_CircleQueue(CQueue queue, void *data)
{
    if (NULL == queue)
    {
        return;
    }
    RET ret = isFull_CircleQueue(queue);
    if (ret == RET_FAIL)
    {
        CircleQueue *pQueue = (CircleQueue *)queue;
        pQueue->m_pAddr[pQueue->m_iTail] = data;
        pQueue->m_iTail = (pQueue->m_iTail + 1) % pQueue->m_iCapacity;
    }
}

//出队列
RET pop_CircleQueue(CQueue queue)
{
    if (RET_OK == isEmpty_CircleQueue(queue))
    {
        return RET_FAIL;
    }

    CircleQueue *pQueue = (CircleQueue *)queue;
    pQueue->m_iHead = (pQueue->m_iHead + 1) % pQueue->m_iCapacity;
    return RET_OK;
}

//判空
RET isEmpty_CircleQueue(CQueue queue)
{
    if (NULL == queue)
    {
        return RET_OK;
    }
    CircleQueue *pQueue = (CircleQueue *)queue;
    if (pQueue->m_iHead == pQueue->m_iTail)
    {
        return RET_OK;
    }
    return RET_FAIL;
}

RET isFull_CircleQueue(CQueue queue)
{
    if (NULL == queue)
    {
        return RET_FAIL;
    }

    CircleQueue *pQueue = (CircleQueue *)queue;
    if ((pQueue->m_iTail + 1) % pQueue->m_iCapacity == pQueue->m_iHead)
    {
        return RET_OK;
    }
    else
    {
        return RET_FAIL;
    }
}

//获取头结点
void * front_CircleQueue(CQueue queue)
{
    if (NULL == queue)
    {
        return NULL;
    }

    CircleQueue *pQueue = (CircleQueue *)queue;
    return pQueue->m_pAddr[pQueue->m_iHead];
}

//当前元素个数
int size_CircleQueue(CQueue queue)
{
    if (NULL == queue)
    {
        return 0;
    }

    CircleQueue *pQueue = (CircleQueue *)queue;
    int size = pQueue->m_iTail - pQueue->m_iHead;
    if (size < 0)
    {
        size += pQueue->m_iCapacity;
    }
    return size;
}