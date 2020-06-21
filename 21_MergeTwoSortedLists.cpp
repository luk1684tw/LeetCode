#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode();
        ListNode *head;

        head = ans;

        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 == nullptr) {
                cout << "in sec1 " << l1->val << endl;
                ans->next = l1;
                l1 = l1->next;
            } else if (l1 == nullptr && l2 != nullptr) {
                cout << "in sec2 " << l2->val << endl;
                ans->next = l2;
                l2 = l2->next;
            } else {
                if (l1->val <= l2->val) {
                    cout << "in sec3-1 " << l1->val << endl;
                    ans->next = l1;
                    l1 = l1->next;
                } else {
                    cout << "in sec3-2 " << l2->val << endl;
                    ans->next = l2;
                    l2 = l2->next;
                }
            
            }
            ans = ans->next;
        }
        return head->next;
    }
};

int main(void) {
    vector<int> tmp1, tmp2;
    int x;
    ListNode* head_a, * head_b, *ans;
    Solution sol;

    while (cin >> x) {
        if (x == 0) break;
        tmp1.push_back(x);
    }

    ListNode a{tmp1[0]};
    head_a = &a;

    ListNode* iter = &a;
    
    for (int i = 1; i < tmp1.size(); i ++) {
        ListNode* tmp = new ListNode(tmp1[i]);
        iter->next = tmp;
        iter = iter->next;
    }

    cout << "\nInput second list\n";

    while (cin >> x) {
        if (x == 0) break;
        tmp2.push_back(x);
    }

    ListNode b(tmp2[0]);
    head_b = &b;

    iter = &b;

    for (int i = 1; i < tmp2.size(); i ++) {
        ListNode* tmp = new ListNode(tmp2[i]);
        iter->next = tmp;
        iter = iter->next;
    }

    ans = sol.mergeTwoLists(head_a, head_b);

    while (ans != nullptr) {
        cout << ans->val;
        ans = ans->next;
    }

    return 0;
}