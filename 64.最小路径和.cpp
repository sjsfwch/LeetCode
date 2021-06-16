/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
# include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int m=grid.size(),n=grid[0].size();
        vector<vector<long>> min_dist(m,vector<long>(n,0));
        // min_dist[m-1][n-1]=grid[m-1][n-1];
        for (int i=m-1;i>=0;i--){
            for (int j=n-1;j>=0;j--){
                if(i+1<m&&j+1<n) 
                    min_dist[i][j]=min(min_dist[i+1][j],min_dist[i][j+1])+grid[i][j];
                else if(i+1<m&&j+1>=n)
                    min_dist[i][j]=min_dist[i+1][j]+grid[i][j];
                else if(i+1>=m&&j+1<n)
                    min_dist[i][j]=min_dist[i][j+1]+grid[i][j];
                else
                    min_dist[i][j]=grid[i][j];
            }
        }
        return min_dist[0][0];
    }
};
// @lc code=end

