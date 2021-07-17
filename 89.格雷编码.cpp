/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    vector<int> grayCode(int n) {
        vector<int> res;
        int total = 1 << n;
        for (int i = 0; i < total; i++) {
            res.push_back(i ^ i >> 1);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution t;
    t.grayCode(2);
    return 0;
}