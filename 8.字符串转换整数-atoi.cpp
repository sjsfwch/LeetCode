/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int cursor=0,lo=INT32_MAX/10,hi=INT32_MAX/10*10;
        long res=0;
        bool positive=true;
        // 找到第一个非空字符
        if (str[0]==' ')
            while(str[cursor]==' ') cursor++;
        // 若非-或数字 返回0
        if(str[cursor]=='-') positive=false,cursor++;
        else if(str[cursor]=='+') positive=true,cursor++;
        else if(str[cursor]>='0' && str[cursor]<='9') positive=true;
        else return 0;
        while(cursor<str.size()){
            int num=str[cursor]-'0';
            if (num>9||num<0) break;
            res*=10;
            // 临界
            if (res==hi){
                if(positive&&(num>=7)) return INT32_MAX;
                else if((!positive)&&num>=8) return INT32_MIN;
            }
            res+=num;
            cursor++;
            if(res>lo) break;
        }
        // 判断是否是break的
        if(cursor<str.size()&&(str[cursor]<='9')&&(str[cursor]>='0')){
            if(positive) return INT32_MAX;
            else return INT32_MIN;
        }
        int result=res;
        return positive?result:(-1*result);
    }
};
// @lc code=end

int main(){
    Solution t;
    auto res=t.myAtoi("  +1");
    return 0;
}
