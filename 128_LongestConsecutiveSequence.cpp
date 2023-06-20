#include <unordered_set>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_map (nums.begin(), nums.end());
        
        int ans = 0;
        for (auto i: nums) {
            if (hash_map.find(i - 1) == hash_map.end()) {
                int cur_num = i + 1;
                int cur_cnt = 1;
                while (hash_map.find(cur_num++) != hash_map.end()) {
                    cur_cnt++;
                }
                ans = max(cur_cnt, ans);
            }
        }
        return ans;
    }
};