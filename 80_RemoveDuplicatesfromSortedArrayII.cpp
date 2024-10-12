#include "vector"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
    
        int w_idx, r_idx, prev, cnt;
        cnt = 1;
        w_idx = 1;
        r_idx = 1;
        prev = nums[0];

        while (r_idx < nums.size())
        {
            if (nums[r_idx] == prev)
            {
                cnt ++;
            }
            else
            {
                prev = nums[r_idx];
                cnt = 1;
            }

            if (cnt <= 2)
            {
                nums[w_idx] = nums[r_idx];
                w_idx ++;
            }

            r_idx ++;
        }

        return w_idx;

    }
};