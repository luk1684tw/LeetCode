#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int cur = 1;
        for (int i = 1; i <= x; cur += 2 * i + 1, i++) {
            if (x == cur) {
                return i;
            } else if (x - cur < 2 * i + 1) {
                return i;
            }
        }

        return 0;
    }
};

int main(void) {
    int x;
    Solution sol;
    while (cin >> x) {
        cout << sol.mySqrt(x) << endl;
    }

    return 0;
}