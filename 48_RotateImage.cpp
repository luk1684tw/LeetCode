#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++) {
            vector<int> next(20, 0);
            int size = matrix.size() - i * 2  - 1;
            int backupX = i, backupY = matrix.size() - i - 1;

            for (int j = 0; j < size; j++) {
                next[j] = matrix[i][i + j];
            }
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < size; k++) {
                    int tmp = matrix[backupX][backupY];
                    matrix[backupX][backupY] = next[k];
                    next[k] = tmp;
                    adjustCoord(backupX, backupY, j + 1);

                }
            }
        }
        return;
    }

    void adjustCoord(int& x, int& y, int turn) {
        switch(turn % 4) {
        case 0:
            y++;
            break;
        case 1:
            x++;
            break;
        case 2:
            y--;
            break;
        case 3:
            x--;
            break;
        default: break;
        }
        return;
    }
};