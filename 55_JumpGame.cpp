#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        if (nums[0] == 0) return false;
        for (vector<int>::reverse_iterator i = nums.rbegin() + 1; i != nums.rend(); i++) {
            if (*i == 0) {
                bool cantReach = true;
                int minSteps = 1;
                for (vector<int>::reverse_iterator j = i + 1; j != nums.rend(); j++) {
                    if ( *j > minSteps++) {
                        cantReach = false;
                    }
                }
                if (cantReach)
                    return false;
            }
        }
        return true;
    }
};