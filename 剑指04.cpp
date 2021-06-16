#include "headers.h"
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;

        int col=matrix[0].size()-1,row=0;
        while(row<matrix.size()&&col>-1){
            if (matrix[row][col]==target) return true;
            else if (matrix[row][col]>target) col--;
            else row++;
        }
        return false;
    }
    int binarySearch(vector<int>& v,int target,int high=1000){
        // 寻找最小的大于等于target的值的index
        int low=0;
        while(low<high){
            int mid=(low+high)>>1;
            if (v[mid]==target) return mid;
            else if (v[mid]>target) high=mid;
            else low=mid+1;
        }
        return low;
    }
};


int main(){
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    Solution t;
    bool p=t.findNumberIn2DArray(matrix,15);
    return 0;
}