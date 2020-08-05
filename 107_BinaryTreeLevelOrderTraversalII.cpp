#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> cur_level, next_level;
        vector<vector<int>> ans;

        cur_level.push(root);

        vector<int> cur;
        while (!cur_level.empty()) {
            TreeNode* node = cur_level.front();
            cur_level.pop();  
            if (node != nullptr) {
                cur.push_back(node->val);
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);

                if (cur_level.empty()) {
                    ans.insert(ans.begin(), cur);
                    cur.clear();
                    cur_level.swap(next_level);
                    queue<TreeNode*> empty;
                    next_level.swap(empty);
                }
                for (auto i: cur) {
                    cout << i << " ";
                }
                cout << endl;
            }
        }

        return ans;
    }
};


int main(void) {

}