#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int nCases;
    cin >> nCases;
    for (int i = 0; i < nCases; i++) {
        int M, N, Q;
        string input;
        cin >> M >> N >> Q;

        char grid[100][100];
        for (int i = 0; i < M; i++) {
            cin >> input;
            for (int j = 0; j < N; j++) {
                grid[i][j] = input[j];
            }
        }

        int centerX, centerY;
        cout << M << " " << N << " " << Q << endl;
        for (int i = 0; i < Q; i++) {
            cin >> centerX >> centerY;
            int r = 0;
            int startX, startY;
            char chara = grid[centerX][centerY];
            bool blocked = false;
            while (!blocked) {
                r++;
                startX = centerX - r;
                startY = centerY - r;
                for (int j = 0; j < 4; j++) {
                    for (int k = 0; k < 2 * r; k++) {
                        // cout << "X: " << startX << " Y: " << startY << endl;
                        if (startX < 0 || startY < 0 || startX >= M || startY >= N) {
                            blocked = true;
                            break;
                        }
                        switch (j) {
                            case 0:
                                if (grid[startX][startY++] != chara) {
                                    blocked = true;
                                }
                                break;
                            case 1:
                                if (grid[startX++][startY] != chara) {
                                    blocked = true;
                                }
                                break;

                            case 2:
                                if (grid[startX][startY--] != chara) {
                                    blocked = true;
                                }
                                break;
                            case 3:
                                if (grid[startX--][startY] != chara) {
                                    blocked = true;
                                }
                                break;
                            default:
                                break;
                        }
                        if (blocked)
                            break;
                    }
                    if (blocked)
                        break;
                }
            }
            cout << 2 * r - 1 << endl;
        }
    }

    return 0;
}