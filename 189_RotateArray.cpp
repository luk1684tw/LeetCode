#include "vector"
using namespace std;

class Solution {
public:
    int find_hcf(int a, int b)
    {
        if (a == 1 || b == 1)
        {
            return 1;
        }
        else if (a % b == 0)
        {
            return b;
        }
        else
        {
            return find_hcf(b, a % b);
        }
    }


    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1 || nums.size() == 0 || (k % nums.size() == 0))
        {
            return;
        }
        
        int cnt = 0;
        int loop_cnt = 0;
        int loop_iterate_cnt = 0;
        int size = nums.size();
        bool is_loop = false;
        
        k %= size;
        int w_idx = k;
        int temp_val = nums[0];
        loop_iterate_cnt = find_hcf(size, k);
        if (loop_iterate_cnt != 1)
        {
            is_loop = true;
            loop_iterate_cnt = size / loop_iterate_cnt;
        }

        while (cnt != nums.size())
        {
            int temp_val2 = nums[w_idx];
            nums[w_idx] = temp_val;
            temp_val = temp_val2;

            cnt ++;
            loop_cnt ++;

            if (is_loop && (loop_cnt == loop_iterate_cnt))
            {
                int next_start = (w_idx + 1) % size;
                temp_val = nums[next_start];
                w_idx += (k + 1);
                w_idx %= size;

                
                loop_cnt = 0;
            }
            else
            {
                w_idx += k;
                w_idx %= size;
            }
        }
    }
};