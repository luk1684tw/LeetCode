#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

typedef struct character {
    char alphabet;
    int count;
} chara; 

bool myCompare(chara x1, chara x2) {
    if (x1.count > x2.count) return true;
    else if (x1.count < x2.count) return false;
    else if (x1.alphabet < x2.alphabet) return true;
    else return false;
}

int main(void) { 
    int nCases;
    cin >> nCases;
    string testcase;
    chara counter[26];

    cin.get(); // to handle ENTER

    for (int i = 0; i < 26; i++) {
        counter[i].alphabet = 'A' + i;
        counter[i].count = 0;
    }

    for (int i = 0; i < nCases; i++) {
        getline(cin, testcase);

        for (auto x: testcase) {
            if (isalpha(x)) {
                char xUpper = toupper(x);
                counter[xUpper - 'A'].count++;
            }
        }
    }
    
    sort(counter, counter + 26, myCompare);

    for (auto x: counter) {
        if (x.count == 0) break;
        cout << x.alphabet << " " << x.count << endl;
    }

    return 0;
}