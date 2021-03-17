/***********************************************************                                          *
* Time: 2021/3/16                                           
* Author: Kcrise                                          
***********************************************************/

#include "LinkedList.h"

//初始化链表
List initLinkedList()
{
    List pList = (List) calloc(1, sizeof(LinkedList));
    if (NULL == pList)
    {
        return NULL;
    }

    pList->pHead = NULL;
    pList->len = 0;
    return pList;
}

// 头插入
RET pushFront(List pList, DATA data)
{
    if (NULL == pList || NULL == data)
    {
        return RET_FAIL;
    }

    Node *pNewNode = (Node*)calloc(1, sizeof(Node));
    if (NULL == pNewNode)
    {
        return RET_FAIL;
    }

    pNewNode->data = data;
    pNewNode->next = pList->pHead;
    pList->pHead = pNewNode;
    ++pList->len;
    return RET_OK;
}

// 尾插入
RET pushBack(List pList, DATA data)
{
    if (NULL == pList || NULL == data)
    {
        return RET_FAIL;
    }

    Node *pNewNode = (Node *)calloc(1, sizeof(Node));
    if (NULL == pNewNode)
    {
        return RET_FAIL;
    }
    pNewNode->data = data;
    pNewNode->next = NULL;

    if (NULL == pList->pHead && pList->len == 0)
    {
        pList->pHead = pNewNode;
        ++pList->len;
        return RET_OK;
    }

    Node *pCur = pList->pHead;
    while(NULL != pCur->next)
    {
        pCur = pCur->next;
    }

    pCur->next = pNewNode;
    ++pList->len;
    return RET_OK;
}

// 按位置插入
RET insertListByPos(List pList, int pos, DATA data)
{
    if (NULL == pList || NULL == data)
    {
        return RET_FAIL;
    }

    if (pos < 0 || pos > pList->len)
    {
        return RET_FAIL;
    }

    if (pos == 0)
    {
        pushFront(pList, data);
        return RET_OK;
    }

    Node *pNewNode = (Node *) calloc(1, sizeof(Node));
    if (NULL == pNewNode)
    {
        return RET_FAIL;
    }

    Node *pPre = pList->pHead;
    int loop = pos - 1;
    while (loop--)
    {
        pPre = pPre->next;
    }

    pNewNode->data = data;
    pNewNode->next = pPre->next;
    pPre->next = pNewNode;
    ++pList->len;
    return RET_OK;
}

// 删除第一个节点
RET popFront(List pList, FREE Free)
{
    if (NULL == pList)
    {
        return RET_FAIL;
    }

    Node* pNode = pList->pHead;
    if (NULL == pNode)
    {
        return RET_OK;
    }

    pList->pHead = pNode->next;
    if (NULL != Free)
    {
        Free(pNode->data);
    }

    free(pNode);
    pNode = NULL;
    --pList->len;
    return RET_OK;
}

// 删除最后一个节点
RET popBack(List pList, FREE Free)
{
    if (NULL == pList || NULL == pList->pHead)
    {
        return RET_FAIL;
    }

    Node* pCur = pList->pHead;
    if (NULL == pCur->next)
    {
        if (Free)
        {
            Free(pList->pHead->data);
        }
        pList->pHead = NULL;
        free(pCur);
        pCur = NULL;
    }
    else
    {
        while (pCur->next->next)
        {
            pCur = pCur->next;
        }
        Node* pNode = pCur->next;
        pCur->next = NULL;
        if (NULL != Free)
        {
            Free(pNode->data);
        }
        free(pNode);
        pNode = NULL;
    }
    --pList->len;
    return RET_OK;
}

// 遍历打印链表
void foreachLinkedList(List pList, PRINT print)
{
    if (NULL == pList)
    {
        return;
    }
    Node* pCur = pList->pHead;
    while (NULL != pCur)
    {
        print(pCur->data);
        pCur = pCur->next;
    }

    printf("\n");
}

//清空链表
RET clearLinkedList(List pList, FREE Free)
{
    if (pList == NULL)
    {
        return RET_FAIL;
    }

    while (pList->len)
    {
        popFront(pList, Free);
        //popBack(pList, Free);
    }
    return RET_OK;
}

//销毁链表
RET destroyLinkedList(List pList, FREE Free)
{
    if (NULL == pList)
    {
        return RET_FAIL;
    }

    int Ret = clearLinkedList(pList, Free);
    if (Ret == RET_OK)
    {
        free(pList);
        pList = NULL;
        return RET_OK;
    }
    return RET_FAIL;
}

//链表反转
List reverseLinkedList(List pList)
{
    if (NULL == pList || NULL == pList->pHead || NULL == pList->pHead->next)
    {
        return pList;
    }

    Node *pPre = NULL;
    Node *pCur = pList->pHead;
    Node *pNext = NULL;
    while (NULL != pCur)
    {
        pNext = pCur->next;
        pCur->next = pPre;
        pPre = pCur;
        pCur = pNext;
    }
    pList->pHead = pPre;

    return pList;
}