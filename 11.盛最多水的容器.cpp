/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int res=0;
        while(lo<hi){
            res=max(res,(hi-lo)*min(height[lo],height[hi]));
            if(height[lo]<height[hi]) lo++;
            else hi--;
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution t;
    int tmp[]={1,8,6,2,5,4,8,3,7};
    vector<int> input(tmp,tmp+sizeof(tmp)/sizeof(int));
    t.maxArea(input);
    return 0;
}