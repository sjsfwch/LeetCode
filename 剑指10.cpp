

class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        long long a=0,b=1,count=1;
        while(count<n){
            count++;
            long long tmp=b;
            b=(a+b)%1000000007;
            a=tmp;
        }
        return b;
    }
};

int main(){
    Solution s;
    auto x=s.fib(8);
    return 0;
}