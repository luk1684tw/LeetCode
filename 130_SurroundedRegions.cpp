class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row, col;
        row = board.size();
        col = board[0].size();
        

        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'Y';
                }
            }
        }

        int index_r = 0, index_c = 0;
        int count = 0;
        while (count < ((row + col) * 2 - 4)) {
            if (board[index_r][index_c] == 'O') {
                // cout << "original " << index_r << " " << index_c << endl;
                iterate(board, index_r - 1, index_c);
                iterate(board, index_r + 1, index_c);
                iterate(board, index_r, index_c - 1);
                iterate(board, index_r, index_c + 1);
            }

            count++;
            if ((index_r == 0) && ((index_c + 1) < col)) {
                index_c ++;
            } else if (((index_r + 1) < row) && (index_c == (col - 1))) {
                index_r ++;
            } else if ((index_r == (row - 1)) && ((index_c - 1) >= 0)) {
                index_c --;
            } else if (((index_r - 1) >= 0) && (index_c == 0)) {
                index_r --;
            }
            
        }

        for (int i = 1; i < row - 1; i++) {
            for (int j = 1; j < col - 1; j++) {
                if (board[i][j] == 'Y') {
                    board[i][j] = 'X';
                }
            }
        }

    }

    void iterate(vector<vector<char>>& board, int row, int col) {
        // cout << row << " " << col << endl;
        if (row == board.size() || col == board[0].size() || row < 0 || col < 0 || board[row][col] == 'X' || board[row][col] == 'O') {
            return;
        }
        if (board[row][col] == 'Y') {
            // cout << "modify: " << row << " " << col << endl;
            board[row][col] = 'O';
            iterate(board, row - 1, col); // up
            iterate(board, row + 1, col); // down
            iterate(board, row, col - 1); // left
            iterate(board, row, col + 1); // right
        }
    }
};