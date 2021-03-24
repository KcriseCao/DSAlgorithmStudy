/***********************************************************                                          *
* Time: 2021/3/19                                           
* Author: Kcrise                                          
***********************************************************/

#ifndef DSALSTUDY_SEQSTACK_H
#define DSALSTUDY_SEQSTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../01Array/Public.h"
#define MAX 1024

typedef struct SEQ_STACK
{
    size_t size;
    void *data[MAX];
} SeqStack;

typedef void* SStack;

//初始化
SStack initSeqStack();

//入栈
RET pushStack(SStack pStack, void *data);

//出栈
void popStack(SStack stack);

//获取栈顶元素
void * topStack(SStack stack);

//获取栈的大小
size_t getSizeStack(SStack stack);

//销毁栈
void destroyStack(SStack *stack);

#endif //DSALSTUDY_SEQSTACK_H
