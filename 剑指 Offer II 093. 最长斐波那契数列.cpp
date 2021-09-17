#include "headers.h"

class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[i][j]为以arr[i],arr[j]为最后两个元素的子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 0));
        unordered_map<int, int> mp;
        int res = 0;
        for (int i = 0; i < n; ++i) mp[arr[i]] = i;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int tmp = arr[i] - arr[j];
                if (mp.find(tmp) != mp.end()) {
                    dp[i][j] = dp[j][mp[tmp]] + 1;
                } else {
                    dp[i][j] = 2;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};