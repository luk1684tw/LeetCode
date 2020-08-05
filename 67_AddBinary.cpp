#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int size_a, size_b, i = 0;

        size_a = a.size();
        size_b = b.size();

        cout << a << " " << b << endl;

        while (size_a > 0 && size_b > 0) {
            ans += a[--size_a] + b[--size_b] - '0';
        }

        cout << ans << endl;

        while (size_a > 0) {
            ans += a[--size_a];
        }

        while (size_b > 0) {
            ans += b[--size_b];
        }
        cout << ans << endl;

        int cIn = 0;
        for (int i = 0; i < ans.size(); i++) {
            int num = ans[i] - '0' + cIn;
            cout << num << " " << i << " ";
            cIn = 0;
            cIn = num / 2;
            ans[i] = char(num % 2) + '0';

            cout << ans[i] << " " << cIn << endl;
        }

        if (cIn == 1) {
            ans += '1';
        }

        reverse(ans.begin(), ans.end());

        return ans;   
    }
};

int main(void) {
    string a, b, c;
    a = "111111"; // 10
    b = "1"; // 11

    // 10101 = 21
    Solution sol;
    c = sol.addBinary(a, b);
    cout << c;

    return 0;
}