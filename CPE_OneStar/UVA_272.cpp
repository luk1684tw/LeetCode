#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string testcase;
    bool first = true;
    
    while (getline(cin, testcase)) {
        for (auto i: testcase) {
            if (i == '\"') {
                if (first) {
                    cout << "``";
                } else {
                    cout << "\'\'";
                }
                first = !first;
            } else {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}