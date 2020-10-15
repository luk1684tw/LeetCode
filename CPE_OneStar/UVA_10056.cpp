#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void) {
    int S;
    cin >> S;
    while (S > 0) {
        int N, target;
        float prob, ans = 1.0;

        cin >> N >> prob >> target;
        if (prob == 0) {
            cout << "0.0000" << endl;
        } else {
            float r = pow(1 - prob, N);
            for (int i = 1; i < target; i++) {
                ans *= (1 - prob);
            }
            ans *= prob;
            cout << fixed << setprecision(4) << ans / (1 - r) << endl;
        }
        S--;
    }
}