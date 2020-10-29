#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<char, string> Map ({
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
});

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.length())
            return vector<string>();

        vector<string>ans;
        trace(ans, digits, "");
        return ans;
    }

    void trace(vector<string> &ans, string digits, string current)
    {
        if (!digits.length())
        {
            ans.push_back(current);
            return;
        }        
        else 
        {
            for (auto i: Map[digits[0]])
            {
                trace(ans, digits.substr(1), current + i);
            }
            return;
        }
    }
};