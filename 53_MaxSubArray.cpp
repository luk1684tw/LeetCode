#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int ans = nums[0];
        int cur = ans;
        for (int i = 1; i < nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(cur, ans);
        }
        return ans;
    }
};

int main(void) {
    vector<int> test {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    Solution sol;

    int ans = sol.maxSubArray(test);

    cout << ans;

    return 0;
}