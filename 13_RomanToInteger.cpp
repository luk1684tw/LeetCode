#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int romanToInt(string s) {
        int sol = 0;
        int len = s.size();

        for (int i = 0; i < len; i++) {
            switch (s[i])
            {
            case 'I':
                if (i < len - 1) {
                    if (s[i + 1] == 'V') {
                        i ++;
                        sol += 4;
                    } else if (s[i + 1] == 'X') {
                        i ++;
                        sol += 9;
                    } else {
                        sol += 1;
                    }
                } else {
                    sol += 1;
                }
                break;
            case 'V':
                sol += 5;
                break;
            case 'X':
                if (i < len - 1) {
                    if (s[i + 1] == 'L') {
                        i ++;
                        sol += 40;
                    } else if (s[i + 1] == 'C') {
                        i ++;
                        sol += 90;
                    } else {
                        sol += 10;
                    }
                } else {
                    sol += 10;
                }
                break;
            case 'L':
                sol += 50;
                break;
            case 'C':
                if (i < len - 1) {
                    if (s[i + 1] == 'D') {
                        i ++;
                        sol += 400;
                    } else if (s[i + 1] == 'M') {
                        i ++;
                        sol += 900;
                    } else {
                        sol += 100;
                    }
                } else {
                    sol += 100;
                }
                break;
            case 'D':
                sol += 500;
                break;
            case 'M':
                sol += 1000;
                break;
            default:
                cout << "unsupported Roman Integer" << endl;
                break;
            }
        }
        return sol;
    }
};


int main(void) {
    Solution sol;
    string x;

    cin >> x;
    sol.romanToInt(x);

    return 0;
}