#define _CRT_SECURE_NO_WARNINGS 1
#include"SListnode.h"
struct ListNode 
{   
    int val;
    struct ListNode *next;
};
 


//删除链表中等于给定值 val 的所有节点
struct ListNode* removeElements(struct ListNode* head, int val)
{
    //1.链表为空
    if (head == NULL)
        return head;
    struct ListNode* pmove = head;
    struct ListNode* pnext = pmove->next;
    //2.链表不为空,并且当前有两个以上节点
    while (pnext != NULL)
    {
        //2-1.第一个节点就是要删除的节点,需要修改头指针指向
        if (head->val == val)
        {
            head = pnext;
            free(pmove);
            pmove = head;
            pnext = pnext->next;
        }
        //2-2.第一个节点不是要删除的节点
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

    //2-3.只有一个节点
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

//反转一个单链表
struct ListNode* reverseList(struct ListNode* head)
{
    //没有节点
    if (head == NULL) return head;
    struct ListNode* p1 = head;
    struct ListNode* p2 = p1->next;
    //一个节点
    if (p2 == NULL) return head;
    //两个节点
    if (p2->next == NULL)
    {
        p2->next = p1;
        p1->next = NULL;
        head = p2;
        return head;
    }
    //多个节点
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
//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
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
//输入一个链表，输出该链表中倒数第k个结点
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
//将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的
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