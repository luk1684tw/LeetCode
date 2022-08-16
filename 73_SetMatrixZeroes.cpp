#include "vector"
#include "set"
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rols, cols;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    rols.insert(i);
                    cols.insert(j);
                }
            }
        }

        for (auto i : rols)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                matrix[i][j] = 0;
            }
        }

        for (auto i : cols)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                matrix[j][i] = 0;
            }
        }
        return;
    }
};