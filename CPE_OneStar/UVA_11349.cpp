#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
    int T;
    cin >> T;
    cin.get();
    for (int i = 1; i <= T; i++) {
        bool symmetric = true;
        bool negFound = false;
        int N;
        long long matrix[100][100] = {0};
        string input, n;

        getline(cin, input);
        N = stoi(input.substr(4));

        for (int r = 0; r < N; r++) {
            int c = 0;
            long long num;
            getline(cin, input);
            istringstream is(input);
            while (is >> num) {
                if (num < 0) {
                    negFound = true;
                    break;
                }
                matrix[r][c++] = num;
            }
        }

        // cout << "input matrix: \n";
        // for (int r = 0; r < N; r++) {
        //     for (int c = 0; c < N; c++) {
        //         cout << matrix[r][c] << " ";
        //     }
        //     cout << endl;
        // }

        if (negFound) {
            cout << "Test #" << i << ": " << "Non-symmetric." << endl;
            continue;
        }

        if (N == 1) {
            cout << "Test #" << i << ": " << "Symmetric." << endl;
            continue;
        }

        int center = N - 1;
        for (int r = 0; r < N / 2; r++) {
            for (int c = 0; c < N; c++) {
                if (matrix[r][c] != matrix[center - r][center - c]) {
                    // cout << "non symmetric: " ;
                    // cout << matrix[r][c] << " " << matrix[center -r][center -c] << endl;
                    // cout << "r: " << r << " c: " << c << endl;
                    symmetric = false;
                    break;
                }
            }
        }

        if (N % 2) { // odd
            for (int c = 0; c < center / 2; c++) {
                if (matrix[N / 2][c] != matrix[N / 2][center - c]) {
                    // cout << "non symmetric: " ;
                    // cout << matrix[N / 2][c] << " " << matrix[N / 2][center -c] << endl;
                    symmetric = false;
                    break;
                }
            }
        }
        cout << "Test #" << i << ": " << ((symmetric)? "Symmetric.": "Non-symmetric.") << endl;
    }
}