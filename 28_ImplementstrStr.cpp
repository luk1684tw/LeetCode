#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int i, j, size_1, size_2;
        size_1 = haystack.size();
        size_2 = needle.size();
        if (size_1 == 0 && size_2 == 0) return 0;

        for (i = 0; i < size_1; i ++) {
            if (i + size_2 > size_1) break;
            cout << i << endl;
            for (j = 0; j < size_2; j++) {
                cout << haystack[i + j] << ", " << needle[j] << endl;
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == size_2) {
                return i;
            }
        }
        return -1;
    }
};

int main(void) {
    string s1 = "aaaaa", s2 = "bba";

    Solution sol;

    int ans = sol.strStr(s1, s2);

    cout << endl << ans << endl;
    return 0;
}