#include <iostream>

using namespace std;

int main(void) {
    long int self, opponent;

    while (cin >> self >> opponent) {
        cout << abs(opponent - self) << endl;
    }

    return 0;
}