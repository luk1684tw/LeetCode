#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        bool found = false;

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i);
                    ans.push_back(j);
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        return ans;
    }
};


int main(void) {
    int target = 9;
    vector<int> test = {2, 7, 11, 15}, ans;
    Solution sol;

    cout << "test";

    ans = sol.twoSum(test, target);
    cout << ans[0] << endl << ans[1];

    return 0;
}