#include "headers.h"

class Solution {
   public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        vector<vector<bool>> isvalid_arr(n + 1, vector<bool>(n + 1, false));
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j)
                isvalid_arr[i][j] = isvalid(s, j, i - 1);
        }
        for (int i = 0; i < dp.size(); ++i) dp[i] = i;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (isvalid_arr[i][j]) {
                    dp[i] = min(dp[j] + 1, dp[i]);
                }
            }
        }
        return dp[n] - 1;
    }

    bool isvalid(string &s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo++] != s[hi--]) return false;
        }
        return true;
    }
};