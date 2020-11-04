#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void swap(int& i, int& j) {
        if (i != j) {
            i ^= j;
            j ^= i;
            i ^= j;   
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        findPermute(0, nums.size() - 1, nums);
        return ans;
    }

    void findPermute(int l, int r, vector<int>& nums) {
        if (l == r) {
            ans.push_back(nums);
            return;
        }

        for (int i = l; i <= r; i++) {
            swap(nums[l], nums[i]);
            findPermute(l + 1, r, nums);
            swap(nums[l], nums[i]);
        }
        return;
    }
};