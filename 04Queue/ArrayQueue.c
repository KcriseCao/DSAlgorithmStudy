/***********************************************************                                          *
* Time: 2021/3/26                                           
* Author: Kcrise                                          
***********************************************************/

#include "ArrayQueue.h"

//初始化队列
ARRAY_QUEUE init_Array_Queue(int capacity)
{
    if (capacity < 0)
    {
        return NULL;
    }

    ArrayQueue * pQueue = (ArrayQueue *)calloc(1, sizeof(ArrayQueue));
    if (!pQueue)
    {
        return NULL;
    }

    pQueue->m_pAddr = (void **)calloc(capacity, sizeof(void *));
    if (!pQueue->m_pAddr)
    {
        free(pQueue);
        return NULL;
    }

    pQueue->m_iCapacity = capacity;
    pQueue->m_iLen = 0;
    return pQueue;
}

//入列
void push_ArrayQueue(ARRAY_QUEUE queue, void *data)
{
    if (!queue || !data)
    {
        return;
    }

    ArrayQueue * pQueue = (ArrayQueue *) queue;
    //队列已满
    if (pQueue->m_iLen == pQueue->m_iCapacity)
    {
        //void **pNewAddr = (void **)realloc(pQueue->m_pAddr, 2 * pQueue->m_iCapacity);
        void **pNewAddr = (void **)calloc(2 * pQueue->m_iCapacity, sizeof(void *));
        if (!pNewAddr)
        {
            return;
        }
        memcpy(pNewAddr, pQueue->m_pAddr, pQueue->m_iLen * sizeof(void *));
        free(pQueue->m_pAddr);
        pQueue->m_pAddr = pNewAddr;
        pQueue->m_iCapacity = 2 * pQueue->m_iCapacity;
    }
    pQueue->m_pAddr[pQueue->m_iLen++] = data;
}

//出列
void pop_Array_Queue(ARRAY_QUEUE queue)
{
    if (!queue)
    {
        return;
    }

    ArrayQueue * pQueue = (ArrayQueue *) queue;
    if (pQueue->m_iLen > 0)
    {
        for (int i = 0; i < pQueue->m_iLen - 1; ++i)
        {
            pQueue->m_pAddr[i] = pQueue->m_pAddr[i+1];
        }
        --pQueue->m_iLen;
    }
}

//销毁队列
void destroy_Array_Queue(ARRAY_QUEUE queue)
{
    if (!queue)
    {
        return;
    }

    ArrayQueue * pQueue = (ArrayQueue *) queue;
    if (pQueue->m_pAddr)
    {
        free(pQueue->m_pAddr);
        pQueue->m_pAddr = NULL;
    }

    free(pQueue);
    pQueue = NULL;
}

//获取队列头
void * front_Array_Queue(ARRAY_QUEUE queue)
{
    if (!queue)
    {
        return NULL;
    }

    ArrayQueue * pQueue = (ArrayQueue *) queue;
    if (pQueue->m_iLen <= 0)
    {
        return NULL;
    }

    return pQueue->m_pAddr[0];
}

//获取队列尾
void * back_Array_Queue(ARRAY_QUEUE queue)
{
    if (!queue)
    {
        return NULL;
    }

    ArrayQueue * pQueue = (ArrayQueue *) queue;
    if (pQueue->m_iLen <= 0)
    {
        return NULL;
    }

    return pQueue->m_pAddr[pQueue->m_iLen - 1];
}

//获取队列长度
size_t size_Array_Queue(ARRAY_QUEUE queue)
{
    if (!queue)
    {
        return -1;
    }

    ArrayQueue * pQueue = (ArrayQueue *) queue;
    return pQueue->m_iLen;
}