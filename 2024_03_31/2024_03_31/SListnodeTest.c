#define _CRT_SECURE_NO_WARNINGS 1
#include"SListnode.h"
struct ListNode 
{   
    int val;
    struct ListNode *next;
};
 


//ɾ�������е��ڸ���ֵ val �����нڵ�
struct ListNode* removeElements(struct ListNode* head, int val)
{
    //1.����Ϊ��
    if (head == NULL)
        return head;
    struct ListNode* pmove = head;
    struct ListNode* pnext = pmove->next;
    //2.����Ϊ��,���ҵ�ǰ���������Ͻڵ�
    while (pnext != NULL)
    {
        //2-1.��һ���ڵ����Ҫɾ���Ľڵ�,��Ҫ�޸�ͷָ��ָ��
        if (head->val == val)
        {
            head = pnext;
            free(pmove);
            pmove = head;
            pnext = pnext->next;
        }
        //2-2.��һ���ڵ㲻��Ҫɾ���Ľڵ�
        else
        {
            if (pnext->val == val)
            {
                pmove->next = pnext->next;
                free(pnext);
                if (pmove->next == NULL)
                    return head;
                pnext = pmove->next;
            }
            else
            {
                pmove = pmove->next;
                if (pmove == NULL)
                    return head;
                pnext = pnext->next;
            }
        }
    }

    //2-3.ֻ��һ���ڵ�
    if (pnext == NULL)
    {
        if (pmove->val == val)
        {
            head = pnext;
            free(pmove);
            pmove = NULL;
        }
        return head;
    }
    return head;
}

//��תһ��������
struct ListNode* reverseList(struct ListNode* head)
{
    //û�нڵ�
    if (head == NULL) return head;
    struct ListNode* p1 = head;
    struct ListNode* p2 = p1->next;
    //һ���ڵ�
    if (p2 == NULL) return head;
    //�����ڵ�
    if (p2->next == NULL)
    {
        p2->next = p1;
        p1->next = NULL;
        head = p2;
        return head;
    }
    //����ڵ�
    p1->next = NULL;
    struct ListNode* tail = p2->next;
    while (tail)
    {
        p2->next = p1;
        p1 = tail->next;
        tail->next = p2;
        head = tail;
        if (p1 == NULL) return head;
        p2 = p1->next;
        p1->next = tail;
        head = p1;
        if (p2 == NULL) return head;
        tail = p2->next;
        p2->next = p1;
        head = p2;
    }
    return head;
}
//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���
struct ListNode* middleNode(struct ListNode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
//����һ����������������е�����k�����
int kthToLast(struct ListNode* head, int k)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    if (k >= 2)
    {
        for (int i = 0; i <= k - 2; i++)
        {
            fast = fast->next;
        }
    }
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow->val;
}
//��������������ϲ�Ϊһ���µ������������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵ�
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{

    struct ListNode* phead = NULL;
    struct ListNode* newlist = NULL;
    if (list1 && list2)
    {
        if (list1->val >= list2->val)
        {
            phead = list2;
            newlist = list2;
            list2 = list2->next;
        }
        else
        {
            phead = list1;
            newlist = list1;
            list1 = list1->next;

        }

        while (list1 && list2)
        {
            if (list1->val >= list2->val)
            {
                newlist->next = list2;
                list2 = list2->next;
                newlist = newlist->next;
            }
            else
            {
                newlist->next = list1;
                list1 = list1->next;
                newlist = newlist->next;
            }
        }
    }
    else
    {
        if (list1) return list1;
        else return list2;
    }

    if (list1)
        newlist->next = list1;
    if (list2)
        newlist->next = list2;
    return phead;
}