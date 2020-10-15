#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
    long int D;
    int S;
    while (cin >> S >> D) {
        int pad = (S - 1) * S / 2;
        double target = D + pad;
        int ans = int((sqrt(1 + target * 8) - 1) / 2);
        if (ans * (ans + 1) < 2 * target) {
            cout << ans + 1 << endl;
        } else {
            cout << ans << endl;
        }
    }
    return 0;
}