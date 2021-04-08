class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = head, slow = head;
        while (!(fast == nullptr && slow == nullptr)) {
            if (fast == slow) 
                return fast;

            fast = fast->next;
        }
    }
};