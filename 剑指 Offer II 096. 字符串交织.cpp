#include "headers.h"

class Solution {
   public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 + n2 != s3.size()) return false;
        bool dp[n1 + 1][n2 + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (int j = 0; j < n2 && s2[j] == s3[j]; ++j) {
            dp[0][j + 1] = true;
        }
        for (int i = 0; i < n1 && s1[i] == s3[i]; ++i) {
            dp[i + 1][0] = true;
        }
        for (int i = 1; i <= n1; ++i) {
            for (int j = 1; j <= n2; ++j) {
                char c1 = s1[i - 1], c2 = s2[j - 1], c3 = s3[i + j - 1];
                dp[i][j] =
                    (c1 == c3 && dp[i - 1][j]) || (c2 == c3 && dp[i][j - 1]);
            }
        }
        return dp[n1][n2];
    }
};