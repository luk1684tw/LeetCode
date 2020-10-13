#include <iostream>

using namespace std;

int SumDigit(int testcase) {
    int ans = 0;
    while (testcase > 0) {
        ans += testcase % 10;
        testcase /= 10;
    }

    return ans;
}

int main(void) {
    int testcase;

    while (cin >> testcase) {
        if (testcase == 0) {
            break;
        }
        int temp = SumDigit(testcase);
        while (temp >= 10) {
            temp = SumDigit(temp);
        }
        cout << temp << endl;
    }
    return 0;
}