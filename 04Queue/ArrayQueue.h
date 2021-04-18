/***********************************************************                                          *
* Time: 2021/3/26                                           
* Author: Kcrise                                          
***********************************************************/

#ifndef DSALSTUDY_ARRAYQUEUE_H
#define DSALSTUDY_ARRAYQUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _QUEUE
{
    size_t m_iCapacity;
    size_t m_iLen;
    void **m_pAddr;
} ArrayQueue;

typedef void * ARRAY_QUEUE;

//初始化队列
ARRAY_QUEUE init_Array_Queue(int capacity);

//入列
void push_ArrayQueue(ARRAY_QUEUE queue, void *data);

//出列
void pop_Array_Queue(ARRAY_QUEUE queue);

//销毁队列
void destroy_Array_Queue(ARRAY_QUEUE queue);

//获取队列头
void * front_Array_Queue(ARRAY_QUEUE queue);

//获取队列尾
void * back_Array_Queue(ARRAY_QUEUE queue);

//获取队列长度
size_t size_Array_Queue(ARRAY_QUEUE queue);







#endif //DSALSTUDY_ARRAYQUEUE_H
