#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[0].size(); j ++) {
                if (board[i][j] == word[0]) {
                    bool ans = traverse(board, word, 0, i * board[0].size() + j);
                    if (ans) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool traverse(vector<vector<char>>& board, string word, int index, int curPos) {
        cout << curPos << " " << index << endl;
        int colSize = board[0].size();
        if (board[curPos / colSize][curPos % colSize] == word[index]) {
            bool top = false, bottom = false, left = false, right = false;
            if (word.size() == index + 1)
                return true;

            bool ans;
            char temp = board[curPos / colSize][curPos % colSize];
            board[curPos / colSize][curPos % colSize] = '.';

            if (curPos / colSize) {
               top = traverse(board, word, index + 1, curPos - colSize);
            }
            ans = top;
            if (curPos % colSize > 0 && !ans) {
                left = traverse(board, word, index + 1, curPos - 1);
            }
            ans = ans || left;
            if (curPos % colSize < (colSize - 1) && !ans) {
                right = traverse(board, word, index + 1, curPos + 1);
            }
            ans = ans || right;
            if (curPos / colSize < (board.size() - 1) && !ans) {
                bottom = traverse(board, word, index + 1, curPos + colSize);
            }
            board[curPos / colSize][curPos % colSize] = temp;
            return ans || bottom;        
        } else {
            return false;
        }
    }
};

// a a a a
// a a a a
// a a a a 
// a a a a 
// a a a b
// aaaaaaaaaaaaaaaaaaaa