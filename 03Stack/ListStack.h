/***********************************************************                                          *
* Time: 2021/3/20                                           
* Author: Kcrise                                          
***********************************************************/

#ifndef DSALSTUDY_LISTSTACK_H
#define DSALSTUDY_LISTSTACK_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE
{
    void *data;
    struct NODE *next;
} Node;

typedef struct LIST_STACK
{
    size_t len;
    Node *pHead;
} LStack;


//初始化栈
LStack * initListStack();

//入栈
void pushListStack(LStack *pStack, void *data);

//出栈
void popListStack(LStack *pStack);

//获取栈顶元素
void * topListStack(LStack *pStack);

//获取栈的长度
size_t getListStackLen(LStack *pStack);

//销毁栈
void destroyListStack(LStack *pStack);

#endif //DSALSTUDY_LISTSTACK_H
