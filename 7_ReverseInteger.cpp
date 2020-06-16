#include <iostream>
#include <climits>

class Solution {

public:
    int reverse(int x) {
        int rev = 0;
        int mod;
        while (x != 0) {
            mod = x % 10;
            if (rev > INT32_MAX / 10 || (rev == INT32_MAX / 10 && mod > 7)) return 0;
            if (rev < INT32_MIN / 10 || (rev == INT32_MIN / 10 && mod < -8 )) return 0;
            rev = rev * 10 + mod;
            x /= 10;
        }

        return rev;
    }

};

int main(void) {
    Solution sol;
    int x;
    std::cin >> x;
    std::cout << sol.reverse(x);
}
