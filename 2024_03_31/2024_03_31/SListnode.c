#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
    SLTDateType data;
    struct SListNode* next;
}SListNode;
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode*));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
    while (plist != NULL)
    {
        printf("%d", plist->data);
        plist = plist->next;
    }
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    SListNode* newnode = BuySListNode(x);
    SListNode* pmove = *pplist;
    while (pmove != NULL)
    {
        pmove = pmove->next;
    }
    pmove->next = newnode;
    newnode = NULL;
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    SListNode* newnode = BuySListNode(x);
    newnode->next = *pplist;
    *pplist = newnode;
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
    SListNode* tail = *pplist;
    while (tail->next->next != NULL)
    {
        tail = tail->next;
    }
    free(tail->next);
    tail->next = NULL;

}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
    SListNode* pmove = *pplist;
    *pplist = pmove->next;
    free(pmove);
    pmove = NULL;
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    while ((plist->data != x) || plist != NULL)
    {
        plist = plist->next;
    }
    return plist;
}
// 单链表在pos位置之后插入x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* newnode = BuySListNode(x);
    newnode = pos->next;
    pos->next = newnode;
}
// 单链表删除pos位置之后的值
void SListEraseAfter(SListNode* pos)
{
    assert(pos && pos->next);
    SListNode* posnext = pos->next;
    pos = pos->next->next;
    free(posnext);
    posnext = NULL;

}
// 在pos的前面插入
// 没有头指针，无法进行前插
void SLTInsert(SListNode** pphead, SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* newnode = BuySListNode(x);
    SListNode* phead = *pphead;
    if (pos == phead)
    {
        newnode->next = pos;
        *pphead = newnode;
    }
    else
    {
        while (phead->next != pos)
        {
            phead = phead->next;
        }
        newnode->next = pos;
        phead->next = newnode;
    }

}

// 删除pos位置
// 没有头指针，无法进行删除
void SLTErase(SListNode** pphead, SListNode* pos)
{
    assert(pos);
    SListNode* phead = *pphead;
    if (pos == phead)
    {
        *pphead = pos->next;
    }
    while (phead != pos)
    {
        phead = phead->next;
    }
    phead->next = pos->next;
    free(pos);
    pos = NULL;
}