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
    bool hasPathSum(TreeNode* root, int sum) {
        if (root == nullptr) return false;
        return preOrder(root, 0, sum);
        
    }

    bool preOrder(TreeNode* root, int cur, int target) {
        if (!root) return false;
        if (!root->left && !root->right) {
            if (cur + root->val == target) {
                return true;
            }
            else return false;
        }
        bool left_ans, right_ans;
        left_ans = preOrder(root->left, cur + root->val, target);
        right_ans = preOrder(root->right, cur + root->val, target);
        
        return left_ans || right_ans;
    }
};