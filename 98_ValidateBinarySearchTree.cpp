#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        vector<int> vals;
        stack<TreeNode*> temp;
        TreeNode* current = root;
        
        while (current || !temp.empty()) {
            if (current) {
                temp.push(current);
                current = current->left;
            } else {
                current = temp.top();
                temp.pop();
                vals.push_back(current->val);
                current = current->right;
            }
        }

        for (int i = 0; i < vals.size() - 1; i++) {
            if (vals[i] >= vals[i + 1]) {
                return false;
            }
        }
        return true;
    }
};