#include "vector"
#include "stack"

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int>& ans = T;
        stack<int> indexs;

        for (int i = 0; i < T.size(); i++) {
            if (indexs.empty() || T[i] < T[indexs.top()]) {
                indexs.push(i);
            } else {
                while (!indexs.empty() && T[indexs.top()] < T[i]) {
                    ans[indexs.top()] = i - indexs.top();
                    indexs.pop();
                }
                indexs.push(i);
            }
        }
        while (!indexs.empty()) {
            ans[indexs.top()] = 0;
            indexs.pop();
        }

        return ans;
    }
};