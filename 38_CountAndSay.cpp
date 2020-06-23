#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string base = "1";
        string ans = "";
        if (n == 1) {
            return base;
        }

        for (int i = 1; i < n; i++) {
            cout << "i = " << i << endl;
            int j = 0;
            ans = "";
            while (j < base.size()) {
                int count = 1;
                while(base[j + 1] == base[j]) {
                    count ++;
                    j ++;
                }
                ans = ans + to_string(count) + base[j++];
                cout << ans << " ";
            }
            base = ans;
            cout << base << endl;
        }
        return ans;
    }
};

int main(void) {
    string ans;

    int n;
    cin >> n;

    Solution sol;
    ans = sol.countAndSay(n);

    cout << ans;

}