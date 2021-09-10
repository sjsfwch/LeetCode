/*
 * @lc app=leetcode.cn id=1894 lang=cpp
 *
 * [1894] 找到需要补充粉笔的学生编号
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long num = chalk.size(), sum = 0;
        for_each(chalk.begin(), chalk.end(), [&sum](const int a) { sum += a; });
        k %= sum;
        for (int i = 0; i < chalk.size(); ++i) {
            if (k < chalk[i]) return i;
            k -= chalk[i];
        }
        return num - 1;
    }
};
// @lc code=end
