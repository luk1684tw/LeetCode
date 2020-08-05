#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        } else {
            string x_str = to_string(x);
            bool ans = true;
            size_t size = x_str.size();

            for (int i = 0; i < size / 2; i++) {
                if (x_str[i] != x_str[size - i - 1]) {
                    ans = false;
                    break;
                }
            }

            return ans;
        }
    }
};


int main(void) {
    int input;
    cin >> input;
    Solution sol;

    cout << sol.isPalindrome(input);

    return 0;
}