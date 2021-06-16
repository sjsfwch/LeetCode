/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        bool positive=true;
        long newDivisor=divisor,newDividend=dividend;
        if (dividend<0) newDividend=0-newDividend,positive=!positive;
        if (divisor<0) newDivisor=0-newDivisor,positive=!positive;
        if(newDividend<newDivisor) return 0;
        long p=1,res=0;
        while((newDivisor<<1)<newDividend) newDivisor<<=1,p<<=1;
        while(newDivisor>=divisor){
            if(newDividend>newDivisor){
                newDividend-=newDivisor;
                res+=p;
            }
            else if(newDividend==newDivisor){
                res+=p;
                break;
            }
            else{
                newDivisor>>=1;
                p>>=1;
            }
        }
        res=positive?(res>2147483647?2147483647:res):(res<-2147483648?-2147483648:0-res);

        return (int)res;
    }
};
// @lc code=end

int main(){
    Solution t;
    auto x= t.divide(-2147483648,-1);
    return 0;
}