#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    string country[2000];
    string name;

    for (int i = 0; i < n; i++) {
        cin >> country[i];
        getline(cin, name);
    }

    sort(country, country + n);

    for (int i = 0; i < n; i++) {
        cout << country[i];

        int count = 1;
        int j = i + 1;
        for (; j < n; j++) {
            if (country[i] != country[j]) break;
            count++;
        }
        i = j - 1;

        cout << " " << count << endl;
    }
    return 0;
}