/***********************************************************                                          *
* Time: 2021/3/19                                           
* Author: Kcrise                                          
***********************************************************/

#include "SeqStack.h"

//初始化
SStack initSeqStack()
{
    SeqStack *pStack = (SeqStack *) calloc(1, sizeof(SeqStack));
    if (!pStack)
    {
        return NULL;
    }

    pStack->size = 0;

    return pStack;
}

//入栈
RET pushStack(SStack stack, void *data)
{
    if (!stack)
    {
        return RET_FAIL;
    }

    SeqStack *pStack = (SeqStack *)stack;
    if (pStack->size == MAX)
    {
        return RET_FAIL;
    }

    pStack->data[pStack->size++] = data;

    return RET_OK;
}

//出栈
void popStack(SStack stack)
{
    if (!stack)
    {
        return;
    }

    SeqStack *pStack = (SeqStack *)stack;
    if (pStack->size == 0)
    {
        return;
    }

    --pStack->size;
}

//获取栈顶元素
void * topStack(SStack stack)
{
    if (!stack)
    {
        return NULL;
    }

    SeqStack *pStack = (SeqStack *)stack;
    if (pStack->size == 0)
    {
        return NULL;
    }
    return pStack->data[pStack->size - 1];
}

//获取栈的大小
size_t getSizeStack(SStack stack)
{
    if (!stack)
    {
        return 0;
    }

    SeqStack *pStack = (SeqStack *)stack;

    return pStack->size;
}

//销毁栈
void destroyStack(SStack *stack)
{
    if (!*stack)
    {
        return;
    }

    free(*stack);
    *stack = NULL;
}
