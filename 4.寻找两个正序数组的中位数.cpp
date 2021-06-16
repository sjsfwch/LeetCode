/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size();
        const int n2 = nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2, nums1);
        int l=0,r=n1,k=(n1+n2+1)/2;
        while(l<r){
            int m1=(l+r)/2;
            int m2=k-m1;
            if (nums1[m1]<nums2[m2-1]) l=m1+1;
            else r=m1;
        }
        int l1, r1, l2, r2;
        int m1 = (l + r) / 2;
        int m2 = k - m1;
        l1=(m1<=0)?INT32_MIN:nums1[m1-1];
        l2=(m2<=0)?INT32_MIN:nums2[m2-1];
        r1=(m1>=n1)?INT32_MAX:nums1[m1];
        r2=(m2>=n2)?INT32_MAX:nums2[m2];
        int lmax=max(l1,l2),rmin=min(r1,r2);
        if ((n1+n2)%2==0) return (lmax+rmin)*0.5;
        else return lmax;


    }
};
// @lc code=end

int main(){
    int i1[]={1,3},i2[]={-1,3};
    vector<int> input1(i1,i1+sizeof(i1)/sizeof(int));
    vector<int> input2(i2,i2+sizeof(i2)/sizeof(int));
    Solution t;
    t.findMedianSortedArrays(input1,input2); 
}