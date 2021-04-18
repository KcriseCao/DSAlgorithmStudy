/***********************************************************                                          *
* Time: 2021/3/28                                           
* Author: Kcrise                                          
***********************************************************/

#ifndef DSALSTUDY_LINKEDQUEUE_H
#define DSALSTUDY_LINKEDQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QUEUE_NODE
{
    void *data;
    struct QUEUE_NODE *next;
} QueueNode;

typedef struct LINKED_QUEUE
{
    int m_iLen;
    QueueNode *m_pHead;
    QueueNode *m_pTail;
} LinkedQueue;

typedef void * LINKED_QUEUE;

//初始化队列
LINKED_QUEUE init_Linked_Queue();

//入队了
void push_Linked_Queue(LINKED_QUEUE queue, void *data);

//出队列
void pop_Linked_Queue(LINKED_QUEUE queue);

//获取队首
void * front_Linked_Queue(LINKED_QUEUE queue);

//获取队尾
void * back_Linked_Queue(LINKED_QUEUE queue);

//销毁队列
void destroy_Linked_Queue(LINKED_QUEUE queue);

//获取当前队列长度
size_t size_Linked_Queue(LINKED_QUEUE queue);

#endif //DSALSTUDY_LINKEDQUEUE_H
