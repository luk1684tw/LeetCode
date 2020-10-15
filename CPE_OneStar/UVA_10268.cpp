#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;



int main(void) {
    string input;
    long long x;
    while (cin >> x) {
        cin.get();
        getline(cin, input);
        istringstream is(input);

        vector<long long> polynomial;
        long long coeff;
        while (is >> coeff) {
            polynomial.push_back(coeff);
        }

        if (polynomial.size() == 1) {
            cout << 0 << endl;
            continue;
        }

        reverse(polynomial.begin(), polynomial.end());
        long long ans = 0;
        for (int i = 1; i < polynomial.size(); i++) {
            ans += polynomial[i] * i * pow(x, i - 1);
        }
        cout << ans << endl;
    }
    return 0;
}