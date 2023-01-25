class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0]) {
            return false;
        }

        int i, j;
        for (i = 0; i < matrix.size() - 1; i++) {
            if ((matrix[i][0] <= target) &&
                (matrix[i + 1][0] > target)) {
                    break;
            }
        }

        if ((matrix[i][0] == target) ||
            (matrix[i][matrix[0].size() - 1] == target)) {
                return true;
        }

        int l, r;
        l = 0;
        r = matrix[0].size() - 1;

        while ((r - l) > 1) {
            int comp = matrix[i][(l + r) / 2];
            if (target == comp) {
                return true;
            } else if (target > comp) {
                l = (l + r) / 2;
            } else {
                r = (l + r) / 2;
            }
        }
        return false;
    }
};