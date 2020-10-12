#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        vector<int> ans;
        while (i < j) {
            int sum = numbers[i] + numbers[j];
            if (sum == target) {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        
        return ans;
    }
};

int main(void) {
    vector<int> test {0, 0, 3, 4};
    int target = 0;

    Solution sol;
    vector<int> ans = sol.twoSum(test, target);

    return 0;
}
