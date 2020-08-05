#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int lens = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                for (int j = i + 1; j < size; j++) {
                    if (nums[j] != val) {
                        nums[i] = nums[j];
                        nums[j] = val;
                        lens++;
                        break;
                    }
                }
            } else {
                lens++;
            }
        }
        return lens;
    }
};

int main(void) {
    Solution sol;
    vector<int> test {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;
    int ans = sol.removeElement(test, val);

    for (int i = 0; i < ans; i++) {
        cout << test[i] << " ";
    }
    return 0;
}