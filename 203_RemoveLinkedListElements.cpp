struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *cur = head;
        ListNode *tmp = cur;
        while (cur != nullptr && cur->val == val)
        {
            tmp = cur;
            cur = cur->next;
            delete(tmp);
        }
        if (cur == nullptr)
        {
            return nullptr;
        }

        ListNode *prev = cur;
        ListNode *ret_head = cur;

        while (cur != nullptr)
        {
            while (cur != nullptr && cur->val == val)
            {
                tmp = cur;
                cur = cur->next;
                delete(tmp);
            }
            if (cur != prev)
            {
                prev->next = cur;
                prev = cur;
            }
            if (cur != nullptr)
            {
                cur = cur->next;   
            }
        }
        return ret_head;
    }
};


