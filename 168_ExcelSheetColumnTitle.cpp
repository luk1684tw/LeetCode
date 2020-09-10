#include <string>

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        int remainder;
        if (n <= 26) {
            ans += char('A' + (n - 1));
            return ans;
        }
        
        while (n > 26) {
            remainder = (--n) % 26;
            ans.insert(ans.begin(), char('A' + remainder));
            cout << ans;
            n /= 26;
        }
        ans.insert(ans.begin(), char('A' + n - 1));
        
        return ans;
    }
};