#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) {
            break;
        }
        int ans = 0;
        int start = int(sqrt((double)a));
        if (pow(start, 2) < a) start++;

        int curSquare = pow(start, 2);
        while (curSquare <= b) {
            ans++;
            curSquare += (++start) * 2 - 1;
        }
        cout << ans << endl;
    }

    return 0;
}