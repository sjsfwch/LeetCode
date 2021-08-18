#include "headers.h"

class NumMatrix {
   private:
    // vector<vector<int>> _matrix;
    vector<vector<long long>> _matrixSum;

   public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        _matrixSum =
            vector<vector<long long>>(m + 1, vector<long long>(n + 1, 0));
        // for (int i = 0; i < m; ++i)
        //     _matrixSum[i + 1][0] = _matrixSum[i][0] + matrix[i][0];
        // for (int i = 0; i < n; ++i)
        //     _matrixSum[0][i + 1] = _matrixSum[0][i] + matrix[0][i];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j)
                _matrixSum[i + 1][j + 1] = _matrixSum[i][j + 1] +
                                           _matrixSum[i + 1][j] + matrix[i][j] -
                                           _matrixSum[i][j];
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return _matrixSum[row2 + 1][col2 + 1] - _matrixSum[row2 + 1][col1] -
               _matrixSum[row1][col2 + 1] + _matrixSum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
    vector<vector<int>> m = {{-1}};
    NumMatrix n(m);
    auto t = n.sumRegion(0, 0, 0, 0);
    return 0;
}