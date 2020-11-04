#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();
        set<vector<int>> presentTriples;
        sort(nums.begin(), nums.end());

        int i = 0;
        while (i < nums.size() - 2)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0)
                {
                    j++;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else 
                {
                    presentTriples.insert(vector<int>({nums[i], nums[j++], nums[k--]}));
                }
            }
            i++;
        }
        return vector<vector<int>>(presentTriples.begin(), presentTriples.end());
    }
};