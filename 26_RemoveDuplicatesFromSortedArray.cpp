#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        int size = nums.size();

        if (size == 0) {
            return 0;
        }

        for (int i = 1; i < size; i++) {
            if (nums[i] > nums[i - 1]) {
                nums[++index] = nums[i];
            }
            cout << endl;
        }

        return index + 1;
    }
};


int main(void) {
    vector<int> test {0,0,1,1,1,2,2,3,3,4};
    Solution sol;

    int len = sol.removeDuplicates(test);

    cout << len << endl;

    for (int i = 0; i < test.size(); i++) {
        cout << test[i] << " ";
    }

    return 0;
}