#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(void) {
    int nCases;
    cin >> nCases;
    for (int i = 1; i <= nCases; i++) {
        cin.get();
        cout << "Case " << i << ":" << endl;
        int weights[36] = {0};
        string inputWeight;
        for (int j = 0; j < 4; j++) {
            getline(cin, inputWeight);
            istringstream is(inputWeight);
            int weight;
            int count = 0;
            while (is >> weight) {
                weights[j * 9 + count] = weight;
                count++;
            }
        }

        int nNums, inputNum;
        cin >> nNums;
        for (int j = 0; j < nNums; j++) {
            cin >> inputNum;
            vector<int> ans;
            int cheapestCost = 200000000;

            for (int k = 2; k <= 36; k++) {
                int cost = 0;
                int num = inputNum;
                while (num > 0) {
                    cost += weights[num % k];
                    num /= k;
                }
                if (cost < cheapestCost) {
                    ans.clear();
                    cheapestCost = cost;  
                }
                if (cost == cheapestCost) {
                    ans.push_back(k);
                }
            }

            cout << "Cheapest base(s) for number " << inputNum << ":";
            for (auto k: ans) {
                cout << " " << k;
            }
            cout << endl;
        }
        if (i != nCases)
            cout << endl;
    }
    return 0;
}