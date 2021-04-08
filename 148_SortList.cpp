class Solution {
public:
    ListNode* sortList(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr)
            size++;
        if (size == 0) return nullptr;
        if (size == 1) return head;


        
    }

    void mergeSort(ListNode* head, int left, int right) {
        if (left < right) {
            mid = (left + right) / 2;
            mergeSort(head, left, mid);
            mergeSort(head, mid + 1, right);

            combine(head, left, right);
        }
    }


};