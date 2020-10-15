#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;

        long long x, y;
        x = (a + b) / 2;
        y = a - x;
        
        if (x < 0 || y < 0) {
            cout << "impossible" << endl;
            continue;
        } else if (x + y != a) {
            cout << "impossible" << endl;
            continue;
        } else if (x - y != b) {
            cout << "impossible" << endl;
            continue;
        } else {
            cout << x << " " << y << endl;
        }
    }
    return 0;
}