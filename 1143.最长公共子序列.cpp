/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        int dp[m + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                dp[i][j] =
                    max(dp[i - 1][j - 1] + int(text1[i - 1] == text2[j - 1]),
                        dp[i][j]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

int main() {
    Solution t;
    t.longestCommonSubsequence("abc", "def");
}
