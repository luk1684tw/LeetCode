#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;
        vector<int> tmp (1, 1);
        ans.push_back(tmp);
        for (int i = 1; i < numRows; i++) {
            vector<int> tmp(2, 1);
            vector<int> prev = ans[i-1];
            for (int j = 1; j < i; j++) {
                tmp.insert(tmp.begin() + j, prev[j - 1] + prev[j]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
int main(void) {
    Solution sol;
    int x = 5;
    vector<vector<int>> ans = sol.generate(x);

    return 0;
}