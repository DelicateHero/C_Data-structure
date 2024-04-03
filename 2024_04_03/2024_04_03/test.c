#define _CRT_SECURE_NO_WARNINGS 1



//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ

/*
����˼·
�������������ֱ���С��x�Ľڵ�ʹ��ڵ���x�Ľڵ㣬�ֱ����β��
*/
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x) {
//        if (pHead == NULL)
//            return NULL;
//
//        struct ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
//        //���������ͷ
//        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));
//        struct ListNode* cur = pHead;
//        while (cur)
//        {
//            //С��x��β�嵽lessTail
//            if (cur->val < x)
//            {
//                lessTail->next = cur;
//                lessTail = lessTail->next;
//            }
//            //���ڵ���x��β�嵽greaterTail
//            else
//            {
//                greaterTail->next = cur;
//                greaterTail = greaterTail->next;
//            }
//            cur = cur->next;
//        }
//        //������������
//        lessTail->next = greaterHead->next;
//        greaterTail->next = NULL;
//        //��ȡ��ͷ
//        pHead = lessHead->next;
//        free(lessHead);
//        free(greaterHead);
//
//        return pHead;
//    }
//};

//�������������ҳ����ǵĵ�һ���������
/*
����˼·��
��������ȼ������������ĳ��ȣ��ó��������������ĳ��ȣ�Ȼ����������ͬʱ�ߣ�ֱ��������ͬ�Ľڵ㣬��Ϊ��һ�������ڵ�
*/
//struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
//    int lenA = 0, lenB = 0;
//    struct ListNode* curA = headA, * curB = headB;
//    //����������
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
//    //�ó��������߼���
//    while (gap--) {
//        longList = longList->next;
//    }
//    //��������ͬʱ�ߣ�ֱ��������ͬ�Ľڵ�
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


//����һ�������ж��������Ƿ��л�

/*
����˼·��
�������ָ��fast,slow, �������ȷʵ�л���fastָ��һ�����ڻ���׷��slowָ�롣
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