#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return vector<int> (1, 1);
        if (rowIndex == 1) return vector<int> (2, 1);
        vector<int> ans (rowIndex + 1, 0);
        ans[0] = 1;
        ans[rowIndex] = 1;
        
        int i, j;
        for (i = 2; i <= rowIndex; i++) {
            for (j = 1; j < (i + 1) / 2; j++) {
                ans[j] = ans[j] + ans[j - 1];
                if (j > 1) {
                    ans[j] -= ans[j - 2];
                    for (int k = j - 3; k >= 0; k--) {
                        ans[j] += ans[k] * int(pow(-1, j - k + 1));
                    }
                }
            }
            if (i % 2 == 0) {
                if (i == 2) {
                    ans[j] = 2;
                } else {
                    ans[j] += ans[j - 1];
                    for (int k = j - 2; k >= 0; k--) {
                        ans[j] += ans[k] * int(pow(-1, j - k + 1));
                    }
                }
                j++;
            }
            for (int mid = (i + 1) / 2, times = 1; j < i; j++, times++) {
                ans[j] = ans[mid - times];
            }
        }
        return ans;
    }
};
