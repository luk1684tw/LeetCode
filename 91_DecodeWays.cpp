#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        for (auto chara: s)
        {
            if (chara != '0')
            {
                break;
            }
            else
            {
                return 0;
            }
        }
        int ans[101] = {0};
        ans[0] = 1;
        ans[1] = 1;
        for (int i = 2; i <= s.size(); i++)
        {
            if (atoi(s.substr(i - 1, 1)) == 0)
            {
                int num = atoi(s.substr(i - 2, 2));
                if (num > 26 || num == 0)
                {
                    return 0;
                }
                else 
                {
                    ans[i] = ans[i - 2];
                    ans[i - 1] = ans[i - 2];
                }
            }
            else if (atoi(s.substr(i - 2, 2)) <= 26)
            {
                if (s[i - 2] == '0')
                {
                    ans[i] = ans[i - 1];
                }
                else
                {
                    ans[i] = ans[i - 1] + ans[i - 2];   
                }
            }
            else
            {
                ans[i] = ans[i - 1];
            }
            //cout << "i: " << i << " ans: " << ans[i] << endl;
        }


        return ans[s.size()];
    }

    int atoi(string s)
    {
        int ret_val = 0;
        for (auto chara : s)
        {
            ret_val = ret_val * 10 + (int)(chara - '0');
        }
        //cout << "atoi: " << ret_val << endl;
        return ret_val;
    }
};