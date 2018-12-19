//
// Created by seadream on 2018/12/16.
//
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
}
}
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pReversedHead = nullptr;
        ListNode* pNode = pHead;
        ListNode* pPrev = nullptr;
        while (pNode != nullptr) {
            ListNode *pNext = pHead->next;

            if (pNext == nullptr) {
                pReversedHead = pNode;
            }
            pNode->next = pPrev;

            pPrev = pNode;
            pNode = pNext;
        }
        return pReversedHead;
    }
};
