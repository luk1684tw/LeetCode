#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        unordered_set<string> ans;
        generateWorker(0, 0, n, ans, "");
        return vector<string>(ans.begin(), ans.end());
    }

    void generateWorker(int left, int right, int n, unordered_set<string> &ans, string current)
    {
        if (left == n)
        {
            while (right < left)
            {
                current += ')';
                right++;
            }
            ans.insert(current);
            return;
        }
        current += '(';
        generateWorker(left + 1, right, n, ans, current);
        while (right <= left)
        {
            current += ')';
            generateWorker(left + 1, right + 1, n, ans, current);
            right++;
        }
        return;
    }
};