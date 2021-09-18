#include "headers.h"

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        dp.push_back(triangle[0]);
        for (int i = 1; i < triangle.size(); ++i) {
            dp.push_back(triangle[i]);
            for (int j = 0; j < dp[i].size(); ++j) {
                if (j - 1 >= 0 && j < dp[i].size() - 1) {
                    dp[i][j] += min(dp[i - 1][j - 1], dp[i - 1][j]);
                } else if (j - 1 >= 0)
                    dp[i][j] += dp[i - 1][j - 1];
                else
                    dp[i][j] += dp[i - 1][j];
            }
        }
        int res = INT32_MAX;
        for (int i = 0; i < dp.back().size(); ++i) {
            res = min(res, dp.back()[i]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> tri = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    Solution t;
    t.minimumTotal(tri);
    return 0;
}