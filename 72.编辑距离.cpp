/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m=word1.size(),n=word2.size();
        if (m*n==0) return m+n;
        int dp[m+1][n+1];
        // vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++) dp[i][0]=i;
        for(int i=0;i<n+1;i++) dp[0][i]=i;
        for(int i=1;i<m+1;i++){
            for (int j=1;j<n+1;j++){
                dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                // 注意是i-1与j-1
                dp[i][j]=min(dp[i-1][j-1]+int(word1[i-1]!=word2[j-1]),dp[i][j]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
int main(){
    Solution t;
    t.minDistance("horse","ros");
    return 0;
}
