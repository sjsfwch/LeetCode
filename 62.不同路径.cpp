/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> tmp(m,vector<int>(n,1));
        for (int i=1;i<m;i++){
            for (int j=1;j<n;j++){
                tmp[i][j]=tmp[i-1][j]+tmp[i][j-1];
            }
        }
        return tmp[m-1][n-1];
    }

};
// @lc code=end

int main(){
    Solution t;
    cout<<(t.uniquePaths(19,13));
    return 0;
}