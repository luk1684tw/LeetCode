#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> temp;
        vector<vector<int>> ans;

        if (root != nullptr) {
            temp.push(root);
            TreeNode* tmp;
            int nextLayerSize = 0;
            int curLayerSize = 1, curSize = 0;
            vector<int> layer;
            while (!temp.empty()) {
                tmp = temp.front();
                temp.pop();
                layer.push_back(tmp->val);
                curSize++;
                if (tmp->left != nullptr) {
                    temp.push(tmp->left);
                    nextLayerSize++;
                }
                if (tmp->right != nullptr) {
                    temp.push(tmp->right);
                    nextLayerSize++;
                }

                if (curSize == curLayerSize) {
                    ans.push_back(layer);
                    layer.clear();
                    curLayerSize = nextLayerSize;
                    nextLayerSize = 0;
                    curSize = 0;
                }
                    
            }
        }
        return ans;
    }
};
