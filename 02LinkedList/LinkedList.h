/***********************************************************                                          *
* Time: 2021/3/16                                           
* Author: Kcrise                                          
***********************************************************/

#ifndef DSALSTUDY_LINKEDLIST_H
#define DSALSTUDY_LINKEDLIST_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../01Array/Public.h"

typedef struct NODE
{
    void *data;
    NODE *next;
} Node;

typedef struct LINKED_LIST
{
    Node * pHead;
    size_t len;
} LinkedList;

typedef LinkedList * List;
typedef void * DATA;
typedef void (*PRINT)(void *data);
typedef bool (*COMPARE)(void *data1, void *data2);
typedef void (*FREE)(void *data);

//初始化链表
List initLinkedList();

// 头插入
RET pushFront(List pList, DATA data);

// 尾插入
RET pushBack(List pList, DATA data);

// 按位置插入
RET insertListByPos(List pList, int pos, DATA data);

// 删除第一个节点
RET popFront(List pList, FREE Free = NULL);

// 删除最后一个节点
RET popBack(List pList, FREE Free = NULL);

// 遍历打印链表
void foreachLinkedList(List pList, PRINT print);

//清空链表
RET clearLinkedList(List pList, FREE Free = NULL);

//销毁链表
RET destroyLinkedList(List pList, FREE Free = NULL);

//链表反转
List reverseLinkedList(List pList);

#endif //DSALSTUDY_LINKEDLIST_H
