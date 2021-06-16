/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows<2) return s;
        vector<string> tmp(numRows,"");
        int cursor=0;
        bool flag=true;
        for(auto c:s){
            tmp[cursor]+=c;
            if (flag){
                cursor++;
                if(cursor==numRows-1) flag=false;
            }
            else{
                cursor--;
                if (cursor==0) flag=true;
            }
        }
        string res="";
        for (auto str:tmp) res+=str;
        return res;
    }
};
// @lc code=end

int main(){
    Solution t;
    t.convert("PAYPALISHIRING",3);
    return 0;
}

