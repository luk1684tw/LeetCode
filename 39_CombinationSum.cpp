#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        findCombinations(ans, candidates, target, 0, cur);

        return ans;
    }

    void printArr(vector<int>& nums) {
        for (auto i: nums) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    
    void findCombinations(vector<vector<int>>& ans, vector<int>& candidates, int target, int index, vector<int> cur) {
        if (sum(cur) < target) {
            cur.push_back(candidates[index]);
            findCombinations(ans, candidates, target, index, cur);
            cur.pop_back();
            if (index + 1 < candidates.size())
                findCombinations(ans, candidates, target, index + 1, cur);
        } else if (sum(cur) == target) {
            ans.push_back(cur);
        }

        return;
    }

    int sum(vector<int> &nums) {
        int ans = 0;
        for (int i: nums) {
            ans += i;
        }
        return ans;
    }
};