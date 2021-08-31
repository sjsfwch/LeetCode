#include "headers.h"

class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n <= 3) {
            sort(nums.begin(), nums.end());
            return nums.back();
        }
        vector<int> dp0(n, 0);
        vector<int> dp1(n, 0);
        // 不偷头部
        dp0[0] = 0;
        dp0[1] = nums[1];
        dp0[2] = max(nums[1], nums[2]);
        for (int i = 2; i < nums.size(); ++i)
            dp0[i] = max(dp0[i - 1], dp0[i - 2] + nums[i]);

        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size() - 1; ++i)
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        return max(dp0[n - 1], dp1[n - 2]);
    }
};