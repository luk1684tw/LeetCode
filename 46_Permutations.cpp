#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        findPermutations(cur, ans, nums, nums.size());
        return ans;
    }

    template <class T>
    void printArr(T& nums) {
        for (auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }

    void findPermutations(vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums, int targetSize) {
        
        if (cur.size() == targetSize) {
            ans.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            cur.push_back(nums[i]);
            int tmp = nums[i];
            nums.erase(nums.begin() + i);
            cout << "candidates left: "
            printArr(nums);
            findPermutations(cur, ans, nums, targetSize);
            nums.push_back(tmp);
            cur.erase(cur.end() - 1);
        }
        return;
    }
};