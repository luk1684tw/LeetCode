#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        
        if (nums[0] == target)
            return 0;
        
        int first = nums[0];
        int ans = -1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                ans = i;
                break;
            }
            if (nums[i - 1] < nums[i] && nums[i] < first)
            {
                if (first < target)
                {
                    break;   
                }
            }
        }
        return ans;
    }
};