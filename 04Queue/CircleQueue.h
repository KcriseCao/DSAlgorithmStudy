/***********************************************************                                          *
* Time: 2021/4/17                                           
* Author: Kcrise                                          
***********************************************************/

#ifndef DSALSTUDY_CIRCLEQUEUE_H
#define DSALSTUDY_CIRCLEQUEUE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef enum
{
    RET_OK = 0,
    RET_FAIL = 1
} RET;

typedef struct _CIRCLE_QUEUE
{
    int m_iCapacity;
    int m_iHead;
    int m_iTail;
    void **m_pAddr;
} CircleQueue;

typedef void* CQueue;

//初始化循环队列
CQueue init_CircleQueue(int capacity);

//销毁循环队列
void destroy_CircleQueue(CQueue queue);

//入队列
void push_CircleQueue(CQueue queue, void *data);

//出队列
RET pop_CircleQueue(CQueue queue);

//判空
RET isEmpty_CircleQueue(CQueue queue);

//判满
RET isFull_CircleQueue(CQueue queue);

//获取头结点
void * front_CircleQueue(CQueue queue);

//当前元素个数
int size_CircleQueue(CQueue queue);

#endif //DSALSTUDY_CIRCLEQUEUE_H
