#include <string>
#include <vector>
using namespace std; 


class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<char> rom_dec_mapping (7);
        rom_dec_mapping[0] = 'M';
        rom_dec_mapping[1] = 'D';
        rom_dec_mapping[2] = 'C';
        rom_dec_mapping[3] = 'L';
        rom_dec_mapping[4] = 'X';
        rom_dec_mapping[5] = 'V';
        rom_dec_mapping[6] = 'I';

        int index = num / 1000;
        while (index > 0)
        {
            ans += "M";
            index--;
        }
        index = num % 1000;
        int factor = 100;

        for (int i = 1; i < rom_dec_mapping.size(); i+=2)
        {
            while (index >= factor)
            {
                if (index / factor == 9)
                {
                    ans += rom_dec_mapping[i + 1];
                    ans += rom_dec_mapping[i - 1];
                    index -= (9 * factor);
                }
                else if (index / factor == 4)
                {
                    ans += rom_dec_mapping[i + 1];
                    ans += rom_dec_mapping[i];
                    index -= (4 * factor);
                }
                else
                {
                    for (int j = 0; j < 2; j++)
                    {
                        int subtract = factor * (((i + j) % 2)? 5: 1);
                        int times = index / subtract;
                        index -= (times * subtract);
                        while (times > 0)
                        {
                            ans += rom_dec_mapping[i + j];
                            times --;
                        }
                    }
                }
            }
            factor /= 10;
        }

        return ans;
    }
};