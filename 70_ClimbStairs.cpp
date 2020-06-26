#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        lookup[0] = 1;
        lookup[1] = 2;

        for (int i = 2; i < n; i++) {
            if (lookup[i] == 0) {
                lookup[i] = lookup[i - 1] + lookup[i - 2];
            }
        }

        return lookup[n-1];
    }

    int lookup[45] = {0}; 
};

int main(void) {
    Solution sol;

    int x;

    while (cin >> x) {
        cout << sol.climbStairs(x) << endl;
    }

    return 0;
}