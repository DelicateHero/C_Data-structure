#define _CRT_SECURE_NO_WARNINGS 1



//编写代码，以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前

/*
解题思路
创建两个链表，分别存放小于x的节点和大于等于x的节点，分别进行尾插
*/
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        if (pHead == NULL)
//            return NULL;
//
//        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
//        //创建链表表头
//        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            //小于x的尾插到lessTail
//            if (cur->val < x)
//            {
//                lessTail->next = cur;
//                lessTail = lessTail->next;
//            }
//            //大于等于x的尾插到greaterTail
//            else
//            {
//                greaterTail->next = cur;
//                greaterTail = greaterTail->next;
//            }
//            cur = cur->next;
//        }
//        //链接两个链表
//        lessTail->next = greaterHead->next;
//        greaterTail->next = NULL;
//        //获取表头
//        pHead = lessHead->next;
//        free(lessHead);
//        free(greaterHead);
//
//        return pHead;
//    }
//};

//输入两个链表，找出它们的第一个公共结点
/*
解题思路：
此题可以先计算出两个链表的长度，让长的链表先走相差的长度，然后两个链表同时走，直到遇到相同的节点，即为第一个公共节点
*/
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    int lenA = 0, lenB = 0;
//    struct ListNode* curA = headA, * curB = headB;
//    //计算链表长度
//    while (curA) {
//        ++lenA;
//        curA = curA->next;
//    }
//
//    while (curB) {
//        ++lenB;
//        curB = curB->next;
//    }
//
//    int gap = abs(lenA - lenB);
//    struct ListNode* longList = headA, * shortList = headB;
//    if (lenA < lenB) {
//        longList = headB;
//        shortList = headA;
//    }
//    //让长链表先走几步
//    while (gap--) {
//        longList = longList->next;
//    }
//    //两个链表同时走，直到遇到相同的节点
//    while (longList && shortList)
//    {
//        if (longList == shortList) {
//            return longList;
//        }
//        else {
//            longList = longList->next;
//            shortList = shortList->next;
//        }
//    }
//
//    return NULL;
//}


//给定一个链表，判断链表中是否有环

/*
解题思路：
定义快慢指针fast,slow, 如果链表确实有环，fast指针一定会在环内追上slow指针。
*/
//typedef struct ListNode Node;
//bool hasCycle(struct ListNode* head) {
//    Node* slow = head;
//    Node* fast = head;
//
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//
//        if (slow == fast)
//            return true;
//    }
//
//    return false;
//}