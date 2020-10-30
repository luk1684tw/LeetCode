#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = -1, right = -1;
        int found = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                left = right = i;
                while(nums[right] == target)
                {
                    right++;
                    if (right == nums.size())
                        break;
                }
                right --;
                break;
            }
        }
        return vector<int>({left, right});
    }
};