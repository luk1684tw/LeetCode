#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (auto i: board) 
        {
            if (!checkRow(i))
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (!checkCol(board, i))
                return false;
        }

        for (int i = 0; i < 9; i++)
        {
            if (!checkSquare(board, i))
                return false;
        }

        return true;
    }

    bool checkRow(vector<char>& board)
    {
        unordered_set<char> row;
        for (char i: board)
        {
            if (i != '.' && !row.insert(i).second)
                return false;
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board, int col)
    {
        unordered_set<char> column;
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] != '.' && !column.insert(board[i][col]).second)
                return false;
        }
        return true;
    }

    bool checkSquare(vector<vector<char>>& board, int num)
    {
        int startRow = (num / 3) * 3, startCol = (num % 3) * 3;
        unordered_set<char> square;
        square.insert(board[startRow + 1][startCol + 1]);
        for (int i = 0; i < 8; i++)
        {
            switch (i / 2)
            {
            case 0:
                if (board[startRow][startCol] != '.' && !square.insert(board[startRow][startCol]).second)
                    return false;
                startCol++;
                break;
            case 1:
                if (board[startRow][startCol] != '.' && !square.insert(board[startRow][startCol]).second)
                    return false;
                startRow++;
                break;
            case 2:
                if (board[startRow][startCol] != '.' && !square.insert(board[startRow][startCol]).second)
                    return false;
                startCol--;
                break;
            case 3:
                if (board[startRow][startCol] != '.' && !square.insert(board[startRow][startCol]).second)
                    return false;
                startRow--;
                break;
            default:
                break;
            }
        }
        return true;
    }
};