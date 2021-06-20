/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        if (nums.size() == 1) return nums[0] == target;
        int n = *nums.rbegin();
        int lo = 0, hi = nums.size() - 1, mi = -1;
        while (lo <= hi) {
            mi = (lo + hi) >> 1;
            if (nums[mi] == target) return true;
            if (nums[lo] == nums[mi] && nums[hi] == nums[mi]) {
                lo++;
                hi--;
                continue;
            }
            // mi在旋转点之前
            if (nums[lo] <= nums[mi]) {
                if (nums[lo] <= target && target < nums[mi])
                    hi = mi - 1;
                else
                    lo = mi + 1;
            }
            // mi在旋转点之后
            else {
                if (nums[mi] < target && target <= n)
                    lo = mi + 1;
                else
                    hi = mi - 1;
            }
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution t;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1,
                        1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1};
    cout << t.search(nums, 13);
    return 0;
}