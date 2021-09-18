#include "headers.h"

class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        int target = sum >> 1;
        bool dp[nums.size() + 1][target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for (int i = 1; i <= nums.size(); ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[nums.size()][target];
    }
};