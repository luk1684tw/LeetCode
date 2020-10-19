#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main(void) {
    map<char, vector<int>> fingerMappings = {
        { 'c', {2, 3, 4, 7, 8, 9, 10} },
        { 'd', {2, 3, 4, 7, 8, 9} },
        { 'e', {2, 3, 4, 7, 8} },
        { 'f', {2, 3, 4, 7} },
        { 'g', {2, 3, 4} },
        { 'a', {2, 3} },
        { 'b', {2} },
        { 'C', {3} },
        { 'D', {1, 2, 3, 4, 7, 8, 9} },
        { 'E', {1, 2, 3, 4, 7, 8} },
        { 'F', {1, 2, 3, 4, 7} },
        { 'G', {1, 2, 3, 4} },
        { 'A', {1, 2, 3} },
        { 'B', {1, 2} }
    };

    int nCases;
    cin >> nCases;

    for (int i = 0; i < nCases; i++) {
        int times[10] = {0};
        int prevPushed[10] = {0};
        string input;
        cin >> input;
        for (auto note: input) {
            int pushed[10] = {0};
            for (vector<int>::iterator finger = fingerMappings[note].begin(); finger != fingerMappings[note].end(); finger++) {
                if (!pushed[*finger - 1]) {
                    pushed[*finger - 1] = 1;
                }
            }

            for (int j = 0; j < 10; j++) {
                if (prevPushed[j] != pushed[j]) {
                    if (pushed[j])
                        times[j] ++;
                    prevPushed[j] = pushed[j];
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            cout << times[j] << " ";
        }
        cout << times[9] << endl;
    }
    return 0;
}