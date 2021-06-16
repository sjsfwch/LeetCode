/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        bool rowFlag = false, colFlag = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) rowFlag = true;
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) colFlag = true;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0)
                for (int i = 0; i < m; i++) matrix[i][j] = 0;
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0)
                for (int j = 0; j < n; j++) matrix[i][j] = 0;
        }
        if (rowFlag) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (colFlag) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end
int main() {
    Solution t;
    vector<vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
    t.setZeroes(matrix);
    return 0;
}
