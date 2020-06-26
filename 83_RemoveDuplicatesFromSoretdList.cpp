#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
 ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* start = head;
        while (start != nullptr) {
            if (start->next == nullptr) {
                break;
            }
            ListNode* tmp = start->next;

            while(tmp->val == start->val) {
                tmp = tmp->next;
            }
            start->next = tmp;

            start = start->next;
        }
        return head;
    }
};

int main(void) {


    return 0;
}