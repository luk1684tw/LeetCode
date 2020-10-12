#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(void) {
    int nCases;
    cin >> nCases;

    int houses[500] = {0};

    for (int i = 0; i < nCases; i++) {
        int nHouses;
        cin >> nHouses;
        for (int j = 0; j < nHouses; j++) {
            int house;
            cin >> house;
            houses[j] = house;
        }
        sort(houses, houses + nHouses);
        int vito = houses[nHouses / 2];
        int ans = 0;
        for (int j = 0; j < nHouses; j++) {
            ans += abs(houses[j] - vito);
        }
        cout << ans << endl;
    }

    return 0;
}