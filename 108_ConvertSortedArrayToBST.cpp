#include <iostream>
#include <vector>

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        for (auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        } else if (nums.size() == 2) {
            TreeNode* root = new TreeNode(nums[1]);
            root->left = new TreeNode(nums[0]);
            return root;
        } else if (nums.size() == 3) {
            TreeNode* root = new TreeNode(nums[1]);
            root->left = new TreeNode(nums[0]);
            root->right = new TreeNode(nums[2]);
            return root;
        } else {
            TreeNode* root = new TreeNode(nums[nums.size() / 2]);
            vector<int> left(nums.begin(), nums.begin() + nums.size() / 2);
            vector<int> right(nums.begin() + nums.size() / 2 + 1, nums.end());
            root->left = sortedArrayToBST(left);
            root->right = sortedArrayToBST(right);
            return root;
        }     
    }

};

int main(void) {

}