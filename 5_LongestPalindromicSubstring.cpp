#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 0 || s.length() == 1) {
            return s;
        }
        int start = 0, len = 0;
        for (int i = 0; i < s.length(); i++) {
            int left = expandCenter(s, i, i);
            int right = expandCenter(s, i, i + 1);
            cout << left << " " << right << endl;
            int found = max(left, right);

            if (found > len) {
                len = found;
                start = i - (len - 1) / 2;
            }

        }
        cout << start << " " << len;
        return s.substr(start, len);

    }

    int expandCenter(string s, int left, int right) {
        int L = left, R = right;

        while (L >= 0 && R < s.length() && s[L] == s[R]) {
            L--;
            R++;
        }

        return R - L - 1;
    }
};

int main(void) {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    Solution sol;
    string s = "abacdef";
    s = sol.longestPalindrome(s);

    return 0;
}