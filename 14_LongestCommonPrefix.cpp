#include <iostream>
#include <vector>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = INT32_MAX;
        string sol = "";
        if (strs.size() == 0) {
            return sol;
        }
        for (auto i: strs) {
            if (len > i.size()) {
                len = i.size();
            }
        }

        bool stop = false;
        for (int i = 0; i < len; i++) {
            char ch = strs[0][i];
            cout << ch << endl;
            for (auto j: strs) {
                if (j[i] != ch) {
                    stop = true;
                    break;
                }
            }
            if (stop) {
                break;
            } else {
                sol += ch;
            }
        }
        return sol;
    }
};


int main(void) {
    Solution sol;
    vector<string> test;
    // test.push_back(("dog"));
    // test.push_back(("racecar"));
    // test.push_back(("flight"));


    string ans = sol.longestCommonPrefix(test);
    cout << "Ans:" << ans;
    return 0;
}