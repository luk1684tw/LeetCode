class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c) {
            return mat;
        }

        vector<vector<int>> ans;
        int origin_row, origin_col;
        origin_row = mat.size();
        origin_col = mat[0].size();
        for (int i = 0; i < r; i++) {
            vector<int> row;
            for (int j = 0; j < c; j++) {
                int order = i * c + j;
                //cout << order / origin_row << " " << order % origin_col << endl;
                row.push_back(mat[order / origin_col][order % origin_col]);
            }

            ans.push_back(row);
        }
        return ans;
    }
};