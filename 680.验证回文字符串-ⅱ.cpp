/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    bool validPalindrome(string s) {
        if (s.size() == 1) return true;
        int left = 0, right = s.size() - 1;
        while (left < right && s[left] == s[right]) {
            left++;
            right--;
        }
        if (left >= right || right - left == 1) return true;
        bool deleteLeft = true, deleteRight = true;
        for (int i = left + 1, j = right; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                deleteLeft = false;
                break;
            }
        }
        if (deleteLeft) return true;
        for (int i = left, j = right - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                deleteRight = false;
                break;
            }
        }
        return deleteRight;
    }
};
// @lc code=end
