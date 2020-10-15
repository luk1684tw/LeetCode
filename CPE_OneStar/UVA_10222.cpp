#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main(void) {
    string keyboard = "1234567890-=qwertyuiop[]asdfghjkl;'zxcvbnm,./";
    string testcase;

    while (getline(cin, testcase)) {
        string ans = "";
        for (auto i: testcase) {
            i = tolower(i);
            if (i != ' ') {
                ans += keyboard[keyboard.find(i) - 2];
            } else {
                ans += ' ';
            }
        }
        cout << ans << endl;
    }

    return 0;
}