/***********************************************************                                          *
* Time: 2021/3/19                                           
* Author: Kcrise                                          
***********************************************************/

#include "SeqStack.h"
#include "ListStack.h"

//测试顺序栈
void testSStack()
{
    SeqStack *pStack = initSeqStack();
    int a = 1, b = 2, c = 3, d = 4;
    pushStack(pStack, &a);
    pushStack(pStack, &b);
    pushStack(pStack, &c);
    pushStack(pStack, &d);

    while (getSizeStack(pStack))
    {
        printf("%d ", *(int *)topStack(pStack));
        popStack(pStack);
    }
    printf("\n");

    destroyStack(pStack);
}

//测试链式栈
void testLStack()
{
    int a = 1, b = 2, c = 3, d = 4;
    LStack *pStack = initListStack();
    if (pStack)
    {
        pushListStack(pStack, &a);
        pushListStack(pStack, &b);
        pushListStack(pStack, &c);
        pushListStack(pStack, &d);
    }
    
    while (getListStackLen(pStack))
    {
        printf("%d ", *(int *)topListStack(pStack));
        popListStack(pStack);
    }

    destroyListStack(pStack);
}

int main(int argc, char *argv[])
{
    //testSStack();

    testLStack();

    return 0;
}