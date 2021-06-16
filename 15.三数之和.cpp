/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        if (nums.size()<3) return vector<vector<int> >();
        // 排序 O(nlog(n))
        sort(nums.begin(),nums.end());
        int l,m,r;
        set<vector<int> > tmpres;
        for(m=1;m<nums.size()-1;m++){
            l=0,r=nums.size()-1;
            while(l<m&&m<r){
                if(nums[l]>0||nums[r]<0) break;
                if(nums[l]+nums[m]+nums[r]>0) r--;
                else if(nums[l]+nums[m]+nums[r]<0) l++;
                else{
                    tmpres.insert(vector<int>{nums[l],nums[m],nums[r]});
                    l++,r--;
                    // 跳过重复的
                    while(l<m&&nums[l]==nums[l-1]) l++;
                    while(m<r&&nums[r]==nums[r+1]) r--;
                }
            }
        }
        vector<vector<int> > res;
        for(auto v:tmpres) res.push_back(v);
        return res;
    }
};
// @lc code=end

int main(){
    Solution t;
    int tmp[]={-2,0,1,1,2};
    vector<int> input(tmp,tmp+sizeof(tmp)/sizeof(int));
    t.threeSum(input);
    return 0;
}