#include "vector"
using namespace std;

#define MIN(a, b) ((a > b)? b: a)
#define MAX(a, b) ((a < b)? b: a)

// solution 1 sliding window
class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int near = 0; // nearest next element when we are at position nums[i]
        int far = 0;  // farest next element when we are at position nums[i]

        while (far < nums.size() - 1)
        {
            int temp_far = far;
            for (int i = near; i <= far; i++)
            {
                temp_far = MAX(temp_far, i + nums[i]);
            }
            near = far + 1;
            far = temp_far;
            ans++;
        }
        return ans;
    }
};

// solution 2 DP
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         if (nums.size() == 1)
//         {
//             return 0;
//         }
        
//         vector<int> ans(nums.size(), 0);

//         ans[0] = 0;
//         ans[1] = 1;
//         for (int i = 2; i < nums.size(); i++)
//         {
//             int min_steps = 10000;
//             for (int j = 0; j < i; j++)
//             {
//                 if (nums[j] < (i - j))
//                 {
//                     continue;
//                 }
//                 min_steps = MIN(min_steps, ans[j] + 1);
//             }
//             ans[i] = min_steps;
//         }
//         return ans[nums.size() - 1];
//     }
// };