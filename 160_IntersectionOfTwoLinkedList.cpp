#include <vector>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode *tmpA = headA, *tmpB = headB;

        while (tmpA != tmpB) {
            if (tmpA == tmpB) {
                return tmpA;
            }

            tmpA = tmpA->next;
            tmpB = tmpB->next;
            
            if (tmpA == nullptr && tmpB == nullptr) return nullptr;

            if (tmpA == nullptr) tmpA = headB;
            if (tmpB == nullptr) tmpB = headA;
        }
        return tmpA;
    }
};