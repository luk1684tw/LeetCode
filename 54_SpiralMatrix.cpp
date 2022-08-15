#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int start_row = 0, start_col = 0;
        int end_row = matrix.size() - 1, end_col = matrix[0].size() - 1;
        vector<int>ans;

        int num_elements = (end_row + 1) * (end_col + 1);
        int i;
        
        while (num_elements > 0)
        {
            for (i = start_col; i <= end_col; i++)
            {
                ans.push_back(matrix[start_row][i]);
                num_elements--;
            }
            if (num_elements == 0)
            {
                break;
            }
            start_row++;

            for (i = start_row; i <= end_row; i++)
            {
                ans.push_back(matrix[i][end_col]);
                num_elements--;
            }
            if (num_elements == 0)
            {
                break;
            }
            end_col--;

            for (i = end_col; i >= start_col; i--)
            {
                ans.push_back(matrix[end_row][i]);
                num_elements--;
            }
            if (num_elements == 0)
            {
                break;
            }
            end_row--;

            for (i = end_row; i >= start_row; i--)
            {
                ans.push_back(matrix[i][start_col]);
                num_elements--;
            }
            if (num_elements == 0)
            {
                break;
            }
            start_col++;
        }
        return ans;
    }
};