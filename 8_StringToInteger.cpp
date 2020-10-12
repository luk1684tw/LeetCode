#include <string>
#include <cstdlib>
#include <cctype>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int sign = 1;
        bool signAppeared = false;
        bool start = false;

        for (auto s: str) {
            if (s == ' ') {
                if (start) return 0;
                continue;
            } else if (s == '-') {
                if (signAppeared) return 0;
                if (start) return 0;
                signAppeared = true;
                start = true;
                sign = -1;
            } else if (s == '+') {
                if (signAppeared) return 0;
                if (start) return 0;
                start = true;
                signAppeared = true;
                sign = 1;
            } else if (isdigit(s)) {
                int digit = (s - '0') * sign;
                if (ans >= INT_MAX/10 || (ans == INT_MAX / 10 && digit > INT_MAX%10))
                    return INT_MAX;
                if (ans <= INT_MIN/10 || (ans == INT_MIN / 10 && digit < INT_MIN%10))
                    return INT_MIN;
                ans = ans * 10 + digit;
            } else {
                break;
            }
            // cout << ans << endl;
        }

        return ans;
    }
};