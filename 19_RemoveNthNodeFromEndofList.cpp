using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* prev = head, *tmp = head;
        int length = 0;
        while (prev != nullptr)
        {
            length++;
            prev = prev->next;
        }
        if (length == 1)
        {
            delete head;
            return nullptr;
        }

        length = length - n;
        if (length == 0)
        {
            tmp = head->next;
            delete head;
            return tmp;
        }

        int cur = 0;
        prev = tmp;
        while (cur < length)
        {
            prev = tmp;
            tmp = tmp->next;
            cur++;
        }
        prev->next = tmp->next;
        delete tmp;
        return head;
    }
};