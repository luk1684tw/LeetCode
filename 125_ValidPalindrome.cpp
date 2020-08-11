#include <string>
#include <locale>

class Solution {
public:
    bool isPalindrome(string s) {
        string tmp;
        for (auto i: s) {
            if (isalnum(i)) {
                tmp += tolower(i);
            }
        }
        int len = tmp.size();
        for (int i = 0; i < len / 2; i++) {
            if (tmp[i] != tmp[len - i - 1]) {
                return false;
            }
        }

        return true;
    }
};