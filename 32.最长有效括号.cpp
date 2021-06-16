/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size()<2) return 0;
        vector<int> dp(s.size(),0);
        int maxLen=0;
        dp[0]=0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i < 2)
                        dp[i] = 2;
                    else
                        dp[i] = dp[i - 2] + 2;
                } else {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        dp[i] = dp[i - 1] + 2;
                        if (i - dp[i - 1] - 2 >= 0)
                            dp[i] += dp[i - dp[i - 1] - 2];
                    }
                }
                maxLen=max(maxLen,dp[i]);
            }
        }
        return maxLen;
    }
};
// @lc code=end

int main(){
    Solution t;
    // string s="(()";
    string s="()(()";
    t.longestValidParentheses(s);
    return 0;
}