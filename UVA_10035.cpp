#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string add1, add2;
    char carry = '0';
    int ans = 0;
    while (cin >> add1 >> add2) {
        if (add1 == "0" && add2 == "0") break;
        reverse(add1.begin(), add1.end());
        reverse(add2.begin(), add2.end());

        int length = max(add1.length(), add2.length());

        for (int i = 0; i < length; i++) {
            if (i < add1.length()) {
                carry = carry + add1[i] - '0';
            }

            if (i < add2.length()) {
                carry = carry + add2[i] - '0';
            }

            if (carry > '9') {
                ans ++;
                carry = '1';
            } else {
                carry = '0';
            }
        }
        if (ans == 0) {
            cout << "No carry operation.";
        } else if (ans == 1) {
            cout << "1 carry operation.";
        } else {
            cout << ans << " carry operations.";
        }
        cout << endl;
        ans = 0;
        carry = '0';
    }
    
    return 0;
}