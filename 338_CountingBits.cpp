#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        if (num == 0) return ans;
        ans.push_back(1);
        if (num == 1) return ans;
        int curPower = 2;

        for (int i = 2; i <= num; i++) {
            if (i == curPower) {
                curPower *= 2;
                ans.push_back(1);
            } else {
                ans.push_back(ans[i - curPower / 2] + 1);
            }
        }
        return ans;
    }
};