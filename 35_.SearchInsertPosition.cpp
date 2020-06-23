#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] >= target) {
                return i;
            }
        }
        return size;
    }
};

int main(void) {
    Solution sol;
    vector<int> test {1, 3, 4, 6};
    int toInsert = 0, ans;

    ans = sol.searchInsert(test, toInsert);

    cout << endl << ans << endl;
}