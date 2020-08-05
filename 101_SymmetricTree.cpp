#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
**/ 
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        else if (root->left == nullptr && root->right != nullptr) return false;
        else if (root->left != nullptr && root->right == nullptr) return false;
        else return checker(root->left, root->right);
    }

    bool checker(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr && q != nullptr) {
            return false;
        } else if (p != nullptr && q == nullptr) {
            return false;
        } else {
            return (p->val == q->val) && checker(p->left, q->right) && checker(p->right, q->left);
        }
    }
};