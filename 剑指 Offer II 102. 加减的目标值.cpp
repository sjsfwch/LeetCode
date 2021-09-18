#include "headers.h"

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((target + sum) & 1 || sum < target) return 0;
        int p = (target + sum) >> 1;
        int dp[nums.size() + 1][p + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j <= p; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1]) dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[nums.size()][p];
    }
};