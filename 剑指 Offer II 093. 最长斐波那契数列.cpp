#include "headers.h"

class Solution {
   public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        // dp[i][j]为以arr[i],arr[j]为最后两个元素的子序列长度
        vector<vector<int>> dp(n, vector<int>(n, 0));
        }
};