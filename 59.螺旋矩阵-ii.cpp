/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int d=0;//d 0:right, 1:down, 2:left, 3:up
        int i=0,j=0,count=1;
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        while(count<=n*n){
            // visit
            matrix[i][j]=count;
            // if change direction
            if (d%4==0&&((j>=n-1)||matrix[i][j+1]>0)) d++;
            else if (d%4==1&&((i>=n-1)||matrix[i+1][j]>0)) d++;
            else if (d%4==2&&((j<=0)||matrix[i][j-1]>0)) d++;
            else if (d%4==3&&((i<=0)||matrix[i-1][j]>0)) d++;
            // move
            if (d%4==0) j++;
            else if (d%4==1) i++;
            else if (d%4==2) j--;
            else i--;  
            count++;
        }
        return matrix;
    }
};
// @lc code=end

int main(){
    Solution t;
    t.generateMatrix(3);
    return 0;
}