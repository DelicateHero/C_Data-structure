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
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
    SListNode* newnode = (SListNode*)malloc(sizeof(SListNode*));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
// �������ӡ
void SListPrint(SListNode* plist)
{
    while (plist != NULL)
    {
        printf("%d", plist->data);
        plist = plist->next;
    }
}

// ������β��
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
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    SListNode* newnode = BuySListNode(x);
    newnode->next = *pplist;
    *pplist = newnode;
}
// �������βɾ
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
    SListNode* pmove = *pplist;
    *pplist = pmove->next;
    free(pmove);
    pmove = NULL;
}

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    while ((plist->data != x) || plist != NULL)
    {
        plist = plist->next;
    }
    return plist;
}
// ��������posλ��֮�����x
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* newnode = BuySListNode(x);
    newnode = pos->next;
    pos->next = newnode;
}
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(SListNode* pos)
{
    assert(pos && pos->next);
    SListNode* posnext = pos->next;
    pos = pos->next->next;
    free(posnext);
    posnext = NULL;

}
// ��pos��ǰ�����
// û��ͷָ�룬�޷�����ǰ��
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

// ɾ��posλ��
// û��ͷָ�룬�޷�����ɾ��
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