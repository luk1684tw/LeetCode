#include <iostream>
#include <iomanip>

using namespace std;

void transformer(long long int num) {
    if (num >= 10000000) {
        transformer(num / 10000000);
        cout << " kuti";
        num %= 10000000;
    }

    if (num >= 100000) {
        transformer(num / 100000);
        cout << " lakh";
        num %= 100000;
    }

    if (num >= 1000) {
        transformer(num / 1000);
        cout << " hajar";
        num %= 1000;
    }

    if (num >= 100) {
        transformer(num / 100);
        cout << " shata";
        num %= 100;
    }

    if (num) {
        cout << " " << num;
    }
}

int main(void) {
    unsigned long long int num;
    int counter = 0;

    while (cin >> num) {
        counter++;
        cout << setw(4) << counter << ".";
        if (num == 0) {
            cout << " 0" << endl;
        } else {
            transformer(num);
            cout << endl;
        }

    }


    return 0;
}