#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ans = 20001;
        int i, j, k;
        for (int i = 0; i < nums.size() - 2; i++) {
            j = i + 1;
            k = nums.size() - 1;

            while (j < k) {
                int cur = nums[i] + nums[j] + nums[k];
                if (cur < target) {
                    j++;
                } else if (cur > target) {
                    k--;
                } else {
                    return cur;
                }
                if (abs(cur - target) < abs(ans - target)) {
                    ans = cur;
                }
            }
        }
        return ans;
    }
};