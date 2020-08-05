#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1) {
            return false;
        }

        stack<char> parentheses;
        map<char, char> mappings;
        mappings['('] = ')';
        mappings['['] = ']';
        mappings['{'] = '}';

        for (auto i: s) {
            if (i == '(' || i == '[' || i == '{') {
                parentheses.push(i);
            } else {
                if (parentheses.empty()) {
                    return false;
                }
                char res = parentheses.top();
                parentheses.pop();
                if (mappings[res] != i) {
                    return false;
                }
            }
        }

        if (!parentheses.empty()) {
            return false;
        } else {
            return true;
        }
    }
};

int main(void) {
    Solution sol;
    string testcase;
    bool status;

    cin >> testcase;

    status = sol.isValid(testcase);
    cout << status;
    return 0;
}