#include <string>

class Solution {
public:
    bool isIsomorphic(string s, string t)
    {
        int length_s;
        length_s = s.size();
        std::map<char, char> char_mappings;

        if (length_s != t.size())
        {
            return false;
        }

        for (int i = 0; i < length_s; i++)
        {
            if (char_mappings.find(s[i]) == char_mappings.end())
            {
                for (int j = 0; j < i; j++)
                {
                    if (t[i] == t[j])
                    {
                        return false;
                    }
                }
                char_mappings[s[i]] = t[i];
            }

            if (char_mappings[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};