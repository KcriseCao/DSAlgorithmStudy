/***********************************************************                                          *
* Time: 2021/3/28                                           
* Author: Kcrise                                          
***********************************************************/

#include "LinkedQueue.h"


//初始化队列
LINKED_QUEUE init_Linked_Queue()
{
    LinkedQueue *pQueue = (LinkedQueue *) calloc(1, sizeof(LinkedQueue));
    if (!pQueue)
    {
        return NULL;
    }

    pQueue->m_iLen = 0;
    pQueue->m_pHead = NULL;
    pQueue->m_pTail = NULL;
    return pQueue;
}

//入队了
void push_Linked_Queue(LINKED_QUEUE queue, void *data)
{
    if (!queue)
    {
        return;
    }

    LinkedQueue *pQueue = (LinkedQueue *)queue;
    QueueNode *pNewNode = (QueueNode *) calloc(1, sizeof(QueueNode));
    if (!pNewNode)
    {
        return;
    }

    pNewNode->data = data;
    pNewNode->next = NULL;
    if (!pQueue->m_pHead)
    {
        pQueue->m_pHead = pNewNode;
    }
    else
    {
        pQueue->m_pTail->next = pNewNode;
    }
    pQueue->m_pTail = pNewNode;
    ++pQueue->m_iLen;
}

//出队列
void pop_Linked_Queue(LINKED_QUEUE queue)
{
    if (!queue)
    {
        return;
    }

    LinkedQueue *pQueue = (LinkedQueue *)queue;
    if (!pQueue->m_pHead)
    {
        return;
    }
    if (pQueue->m_iLen == 1)
    {
        pQueue->m_pTail = NULL;
    }
    QueueNode *pCur = pQueue->m_pHead;
    pQueue->m_pHead = pQueue->m_pHead->next;
    free(pCur);
    pCur = NULL;
    --pQueue->m_iLen;
}

//获取队首
void * front_Linked_Queue(LINKED_QUEUE queue)
{
    if (!queue)
    {
        return NULL;
    }

    LinkedQueue *pQueue = (LinkedQueue *)queue;
    if (pQueue->m_iLen == 0)
    {
        return NULL;
    }

    return pQueue->m_pHead->data;
}

//获取队尾
void * back_Linked_Queue(LINKED_QUEUE queue)
{
    if (!queue)
    {
        return NULL;
    }

    LinkedQueue *pQueue = (LinkedQueue *)queue;
    if (pQueue->m_iLen == 0)
    {
        return NULL;
    }

    return pQueue->m_pTail->data;
}

//销毁队列
void destroy_Linked_Queue(LINKED_QUEUE queue)
{
    if (!queue)
    {
        return;
    }

    LinkedQueue *pQueue = (LinkedQueue *)queue;
    while (pQueue->m_iLen)
    {
        pop_Linked_Queue(pQueue);
    }
}

//获取当前队列长度
size_t size_Linked_Queue(LINKED_QUEUE queue)
{
    if (!queue)
    {
        return -1;
    }

    LinkedQueue *pQueue = (LinkedQueue *) queue;
    return pQueue->m_iLen;
}