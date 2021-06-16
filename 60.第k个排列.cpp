/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */

#include "headers.h"
using namespace std;

// @lc code=start
class Solution {
public:
    const int factoria[10]={1,1,2,6,24,120,720,5040,40320,362880};
    string getPermutation(int n, int k) {
        string s="";
        vector<char> remains={'1','2','3','4','5','6','7','8','9'};
        for(--k;n--;k%=factoria[n]){
            const int i=k/factoria[n];
            s+=remains[i];
            remains.erase(remains.begin()+i);
        }
        return s;
    }
};
// @lc code=end

int main(){
    Solution t;
    t.getPermutation(5,1);
    // for(int i=1;i<=6;i++){
    //     auto s=t.getPermutation(3,i);
    //     cout<<s<<endl;
    // }
    return 0;
}
