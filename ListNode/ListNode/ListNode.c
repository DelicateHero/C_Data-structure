#define _CRT_SECURE_NO_WARNINGS 1\
#include<stdio.h>
#include<stdlib.h>

//��ͷ˫��ѭ������
typedef int LTDataType;
typedef struct ListNode
{
    LTDataType _data;
    struct ListNode* _next;
    struct ListNode* _prev;
}ListNode;
// �������������ͷ���.
ListNode* ListCreate(ListNode* pHead)
{
    //ListNode *head = (ListNode *)malloc(sizeof(ListNode));
    pHead->_data = 0;
    pHead->_next = pHead;
    pHead->_prev = pHead;
    return pHead;
}

// ˫����������
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

// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
    ListNode* cur = pHead->_next;
    while (cur != pHead)
    {
        printf("%d", cur->_data);
        cur = cur->_next;
    }

}

// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->_data = x;
    newnode->_next = pHead;
    newnode->_prev = pHead->_prev;
    pHead->_prev->_next = newnode;
    pHead->_prev = newnode;
}

// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
    assert(pHead && pHead->_next != pHead);
    ListNode* cur = pHead->_prev;
    pHead->_prev = cur->_prev;
    cur->_prev->_next = pHead;
    free(cur);
    cur = NULL;
}

// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->_data = x;
    newnode->_next = pHead->_next;
    pHead->_next = newnode;
    newnode->_prev = pHead;
    newnode->_next->_prev = newnode;
}

// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
    assert(pHead && pHead->_next != pHead);
    ListNode* cur = pHead->_next;
    pHead->_next = cur->_next;
    cur->_next->_prev = pHead;
    free(cur);
    cur = NULL;
}

// ˫���������
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

// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->_data = x;
    newnode->_next = pos;
    newnode->_prev = pos->_prev;
    pos->_prev->_next = newnode;
    pos->_prev = newnode;
}

// ˫������ɾ��posλ�õĽڵ�
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

    //�ȱ�֤���Ϊ0��1��2���������ֹ�Կ�ָ�����next����
    if (head == NULL)
        return NULL;
    else if (head->next == NULL)
        return NULL;
    else if (head->next->next == NULL)
        return NULL;
    while (fast && fast->next)//��֤fast�ǿ�ָ���ʱ�����next����Ҳû����
    {
        fast = fast->next->next;//����ָ�룬����л��ṹ��fast��һֱ�ڻ�����Ȧ��ֱ��slow�ҴҸϹ�����fast��slow�ջ�����
        slow = slow->next;
        if (fast == slow)//����������
        {
            meet = slow;//��¼���������ĵط�
            ent = head;//��һ��ָ���ͷ��ʼ�ߣ�
            while (meet != ent)//�����ĵط��ڻ���������㵽����ڵľ��루����NȦ�������㵽����ڵľ��룩������������ͷ��������ڵľ��룬���Ի�һ��ʾ��ͼ��⡣
            {
                meet = meet->next;
                ent = ent->next;
            }
            return ent;
        }
    }
    return NULL;//ѭ�������꣬˵��û�л�ʽ�ṹ
}