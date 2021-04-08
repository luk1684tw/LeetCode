#include <iostream>
#include <stack>

using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

typedef struct TreeNodePair {
    TreeNode* t1;
    TreeNode* t2;
    
} NodePair;

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        stack<NodePair> s;
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        NodePair t = {
            t1,
            t2
        };
        s.push(t);
        while (!s.empty()) {
            t = s.top();
            // cout << t.t1->val << " " << t.t2->val << endl;
            s.pop();
            t.t1->val += t.t2->val;
            NodePair temp;
            if (t.t1->left != nullptr && t.t2->left != nullptr) {
                temp = {
                    t.t1->left,
                    t.t2->left
                };
                s.push(temp);
            } else {
                t.t1->left = (t.t2->left)? t.t2->left : t.t1->left; 
            }

            if (t.t1->right != nullptr && t.t2->right != nullptr) {
                temp = {
                    t.t1->right,
                    t.t2->right
                };
                s.push(temp);
            } else {
                t.t1->right = (t.t2->right)? t.t2->right : t.t1->right;
            }
        }
        return t1;
    }
};