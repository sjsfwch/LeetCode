/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int d=0;//d 0:right, 1:down, 2:left, 3:up
        int i=0,j=0;
        int m=matrix.size(),n=matrix[0].size();
        vector<int> order;
        vector<vector<bool>> visit(m,vector<bool>(n,false));
        while(order.size()<m*n){
            // visit
            order.push_back(matrix[i][j]);
            visit[i][j]=true;
            // if change direction
            if (d%4==0&&((j>=n-1)||visit[i][j+1])) d++;
            else if (d%4==1&&((i>=m-1)||visit[i+1][j])) d++;
            else if (d%4==2&&((j<=0)||visit[i][j-1])) d++;
            else if (d%4==3&&((i<=0)||visit[i-1][j])) d++;
            // move
            if (d%4==0) j++;
            else if (d%4==1) i++;
            else if (d%4==2) j--;
            else i--;
            
        }
        return order;

    }
};
// @lc code=end

int main(){
    Solution t;
    vector<vector<int>> matrix({{1,2,3,4},{5,6,7,8},{9,10,11,12}});
    t.spiralOrder(matrix);
    return 0;
}