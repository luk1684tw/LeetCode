#include <iostream>
#include <queue>
#include <algorithm>

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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while (!q.empty()) {
            ans ++;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* r = q.front();
                cout << r->val << endl;
                q.pop();
                if (r->left != nullptr) q.push(r->left);
                if (r->right != nullptr) q.push(r->right);

                if (!r->left && !r->right) {
                    return ans;
                }
            }
        }
        return 0;
    }
};