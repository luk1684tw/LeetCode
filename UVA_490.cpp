#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    vector<string> strings;
    string input;

    int maxLen = 0;
    while (getline(cin, input)) {
        strings.push_back(input);
        maxLen = (maxLen > input.length())? maxLen : input.length();
    }
    for (int x = 0; x < maxLen; x++) {
        for (vector<string>::reverse_iterator i = strings.rbegin(); i != strings.rend(); i++) {
            if (x < i->length()) {
                cout << (*i)[x];
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}