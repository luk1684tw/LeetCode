#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int length;
    while (cin >> length) {
        int nums[3000] = {0};
        int occurrance[3000] = {0};
        int num;
        for (int i = 0; i < length; i++) {
            cin >> num;
            nums[i] = num;
        }

        if (length == 1) {
            cout << "Jolly\n";
            continue;
        }

        bool jolly = true;
        for (int i = 1; i < length; i++) {
            occurrance[abs(nums[i - 1] - nums[i])] = 1;
        }

        for (int i = 1; i < length; i++) {
            if (!occurrance[i]) {
                jolly = false;
            }
        }

        if (jolly) {
            cout << "Jolly\n";
        } else {
            cout << "Not jolly\n";
        }
    }
    return 0;
}