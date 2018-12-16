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
};
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {

    }
    ListNode* MeetingNode(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        ListNode *pSlow = pHead->next;
        if (pSlow == nullptr) {
            return nullptr;
        }
        ListNode *pFast = pSlow->next;
        if (pFast == nullptr) {
            return nullptr;
        }
        while (pSlow != nullptr && pFast != nullptr) {
            if (pFast == pSlow) {
                return pFast;
            }

            pSlow = pSlow->next;

            pFast = pFast->next;
            if (pFast != nullptr) {
                if (pFast == pSlow)
                    return pFast;
                else pFast = pFast->next;
            }
        }
        return nullptr;
    }
};