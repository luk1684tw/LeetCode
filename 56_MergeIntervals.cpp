#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return vector<vector<int>> ();
        }

        if (intervals.size() == 1) {
            return intervals;
        }
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        vector<int> cur = intervals[0];
        for (int i = 1; i < intervals.size(); i++) {
            if (cur[1] >= intervals[i][0]) {
                cur[1] = (intervals[i][1] > cur[1])? intervals[i][1]: cur[1];
            } else {
                ans.push_back(cur);
                cur = intervals[i];
            }
        }
        ans.push_back(cur);
        return ans;
    }
};