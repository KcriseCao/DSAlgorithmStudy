/***********************************************************                                          *
* Time: 2021/3/20                                           
* Author: Kcrise                                          
***********************************************************/

#include "ListStack.h"

//初始化栈
LStack * initListStack()
{
    LStack *pStack = (LStack *) calloc(1, sizeof(LStack));
    if (!pStack)
    {
        return NULL;
    }

    pStack->pHead = NULL;
    pStack->len = 0;
    return pStack;
}

//入栈
void pushListStack(LStack *pStack, void *data)
{
    if (!pStack)
    {
        return;
    }

    Node *pNewNode = (Node *) calloc(1, sizeof(Node));
    if (!pNewNode)
    {
        return;
    }

    pNewNode->data = data;
    pNewNode->next = pStack->pHead;
    pStack->pHead = pNewNode;
    ++pStack->len;
}

//出栈
void popListStack(LStack *pStack)
{
    if (!pStack || !pStack->pHead)
    {
        return;
    }
    Node *pCur = pStack->pHead;
    pStack->pHead = pStack->pHead->next;
    --pStack->len;
    free(pCur);
    pCur = NULL;
}

//获取栈顶元素
void * topListStack(LStack *pStack)
{
    if (!pStack || pStack->len == 0)
    {
        return NULL;
    }

    return pStack->pHead->data;
}

//获取栈的长度
size_t getListStackLen(LStack *pStack)
{
    if (!pStack || pStack->pHead)
    {
        return 0;
    }

    return pStack->len;
}

//销毁栈
void destroyListStack(LStack *pStack)
{
    if (!pStack)
    {
        return;
    }

    while (getListStackLen(pStack))
    {
        popListStack(pStack);
    }

    free(pStack);
    pStack = NULL;
}