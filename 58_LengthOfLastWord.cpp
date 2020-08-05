#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) {
            return 0;
        }
        cout << s.size() << endl;
        int ans = 0;
        bool found = false;
        for (int idx = s.size() -1; idx > -1; idx--) {
            if (s[idx] != ' ') {
                ans++;
                found = true;
            } else if (found) {
                break;
            }
            cout << ans << " ";
        }
        return ans;
    }
};

int main(void) {
    string test = "b     a       ";
    Solution sol;

    int ans = sol.lengthOfLastWord(test);

    return 0;
}