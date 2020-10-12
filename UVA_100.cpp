#include <iostream>

using namespace std;

int main(void) {
    int i, j, maxCycles;
    int num1, num2;
    while (cin >> num1 >> num2) {
        i = num1;
        j = num2;
        if (i > j) {
            swap(i, j);
        }
        maxCycles = 0;
        for (int num = i; num <= j; num++) {
            int cycles = 0;
            int n = num;
            while (n != 1) {
                cycles++;
                if (n % 2 == 0) {
                    n /= 2;
                } else {
                    n = 3*n + 1;
                }
            }
            maxCycles = max(maxCycles, cycles);
        }
        cout << num1 << " " << num2 << " " << maxCycles + 1 << endl;
    }
    return 0;
}