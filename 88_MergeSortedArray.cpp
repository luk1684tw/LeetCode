#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m; i < m + n; i++) {
            nums1[i] = nums2[i - m];
        }

        sort(nums1.begin(), nums1.begin() + m + n);
        for (auto i: nums1) {
            cout << i << " ";
        }

        return;
    }
};


int main(void) {
    vector<int> num1 {1, 2, 7, 0, 0, 0};
    vector<int> num2 {2, 5, 6};

    Solution sol;

    sol.merge(num1, 3, num2, 3);

    return 0;
}