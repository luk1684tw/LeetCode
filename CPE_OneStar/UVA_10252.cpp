#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    string a, b;

    while (getline(cin, a)) {
        getline(cin, b);

        int i = 0, j = 0;
        string ans = "";
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while (i < a.length() && j < b.length()) {
            if (a[i] == b[j]) {
                ans += a[i];
                i++; 
                j++;
            } else if (a[i] > b[j]) {
                j++;
            } else {
                i++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}