#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans;
        int div = numRows * 2 - 2;
        for (int i = 0; i < numRows; i++) {
            int curIdx = i;
            while (curIdx < s.length()) {
                if (curIdx % div == 0 || curIdx % div == numRows - 1) {
                    ans += s[curIdx];
                } else {
                    ans += s[curIdx];
                    int nextIdx = curIdx + 2 * (numRows - 1 - i);
                    if (nextIdx < s.length()) {
                        ans += s[nextIdx];
                    }
                }
                curIdx += div;
            }
        }
        return ans;
    }
};