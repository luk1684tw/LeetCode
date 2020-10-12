#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string num;
    while (cin >> num) {
        if (num == "0") break;

        int odd = 0, even = 0;
        for (int i = 0; i < num.length(); i++) {
            if (i % 2) {
                odd += num[i] - '0';
            } else {
                even += num[i] - '0';
            }
        }
        if (abs(odd - even) % 11) {
            cout << num << " is not a multiple of 11.\n";
        } else {
            cout << num << " is a multiple of 11.\n";
        }
    }

    return 0;
}