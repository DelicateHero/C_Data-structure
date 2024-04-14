#define _CRT_SECURE_NO_WARNINGS 1\
#include<stdio.h>
#include<stdlib.h>

//带头双向循环链表
typedef int LTDataType;
typedef struct ListNode
{
    LTDataType _data;
    struct ListNode* _next;
    struct ListNode* _prev;
}ListNode;
// 创建返回链表的头结点.
ListNode* ListCreate(ListNode* pHead)
{
    //ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    pHead->_data = 0;
    pHead->_next = pHead;
    pHead->_prev = pHead;
    return pHead;
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
    assert(pHead);
    assert(pHead->_next != pHead);
    ListNode* cur = pHead;
    ListNode* prev = pHead;
    prev = cur;
    cur = cur->_next;
    if (cur == pHead)
    {
        free(prev);
        prev = NULL;
        pHead->_next = pHead;
        pHead->_prev = pHead;
    }
    pHead->_next = pHead;
    pHead->_prev = pHead;
    while (prev != pHead)
    {
        cur->_prev = pHead;
        free(prev);
        prev = cur;
        cur = cur->_next;
    }
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
    ListNode* cur = pHead->_next;
    while (cur != pHead)
    {
        printf("%d", cur->_data);
        cur = cur->_next;
    }

}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->_data = x;
    newnode->_next = pHead;
    newnode->_prev = pHead->_prev;
    pHead->_prev->_next = newnode;
    pHead->_prev = newnode;
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
    assert(pHead && pHead->_next != pHead);
    ListNode* cur = pHead->_prev;
    pHead->_prev = cur->_prev;
    cur->_prev->_next = pHead;
    free(cur);
    cur = NULL;
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->_data = x;
    newnode->_next = pHead->_next;
    pHead->_next = newnode;
    newnode->_prev = pHead;
    newnode->_next->_prev = newnode;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
    assert(pHead && pHead->_next != pHead);
    ListNode* cur = pHead->_next;
    pHead->_next = cur->_next;
    cur->_next->_prev = pHead;
    free(cur);
    cur = NULL;
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
    ListNode* cur = pHead->_next;
    while (cur != pHead)
    {
        if (cur->_data == x)
            return cur;
        cur = cur->_next;
    }
    return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->_data = x;
    newnode->_next = pos;
    newnode->_prev = pos->_prev;
    pos->_prev->_next = newnode;
    pos->_prev = newnode;
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
    assert(pos);
    //ListNode *cur = pos->_next;
    pos->_next->_prev = pos->_prev;
    pos->_prev->_next = pos->_next;
    free(pos);
}




//Definition for singly - linked list.
struct ListNode 
{
int val;
struct ListNode* next;
};
struct ListNode* detectCycle(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* meet = head;
    struct ListNode* ent = head;

    //先保证结点为0、1、2的情况，防止对空指针进行next操作
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return NULL;
    else if (head->next->next == NULL)
        return NULL;
    while (fast && fast->next)//保证fast是空指针的时候进行next操作也没问题
    {
        fast = fast->next->next;//快慢指针，如果有环结构，fast会一直在环里跑圈，直到slow匆匆赶过来，fast和slow终会相遇
        slow = slow->next;
        if (fast == slow)//这是相遇了
        {
            meet = slow;//记录下来相遇的地方
            ent = head;//让一个指针从头开始走，
            while (meet != ent)//相遇的地方在环里，从相遇点到环入口的距离（或者N圈加相遇点到环入口的距离），正好是链表头部到环入口的距离，可以画一个示意图理解。
            {
                meet = meet->next;
                ent = ent->next;
            }
            return ent;
        }
    }
    return NULL;//循环能走完，说明没有环式结构
}