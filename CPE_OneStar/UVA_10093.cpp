#include <iostream>
#include <cctype>

using namespace std;

int main(void) {
    char input;
    while (cin >> input) {
        if (isdigit(input)) {
            cout << input + 1 << endl;
        } else if (isalpha(input)) {
            if (input >= 'a') {
                cout << 37 + input - 'a';
            }
        }
    }
}