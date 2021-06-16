/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include "headers.h"
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m=matrix.size(),n=matrix[0].size();
        int lo=0,hi=m-1,row=-1;
        // 寻找列
        // [lo,hi]
        while(lo<hi){
            int mi=(lo+hi+1)>>1;
            if (target<matrix[mi][0]) hi=mi-1;
            else lo=mi;
        }
        row=lo;
        lo=0,hi=n-1;
        while(lo<hi){
            int mi =(lo+hi+1)>>1;
            if (target<matrix[row][mi]) hi=mi-1;
            else lo=mi;
        }
        return matrix[row][lo]==target;
    }

};


// @lc code=end
int main(){
    // vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    vector<vector<int>> matrix={{1,1}};
    Solution t;
    cout<<t.searchMatrix(matrix,1);
    return 0;
}
