#include <iostream>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int lowerBound, upperBound;
        cin >> lowerBound >> upperBound;

        if (lowerBound % 2 == 0) {
            lowerBound += 1;
        }

        if (upperBound % 2 == 0) {
            upperBound -= 1;
        }

        int n = (upperBound - lowerBound) / 2 + 1;

        cout << "Case " << i << ": " 
            << (lowerBound + upperBound) * n / 2 << endl;
    }
    return 0;
}