/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> tmp;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            while (!tmp.empty() && nums[i] > nums[tmp.back()]) tmp.pop_back();
            tmp.push_back(i);
            while (!tmp.empty() && i - tmp.front() + 1 > k) tmp.pop_front();
            if (i >= k - 1) res.push_back(nums[tmp.front()]);
        }
        return res;
    }
};
// @lc code=end
