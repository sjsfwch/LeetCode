

class Solution {
public:
    int cuttingRope(int n) {
        if (n<4) return n-1;
        if (n==4) return 4;
        return 3*cut(n-3);
    }
    int cut(int n){
        if (n<4) return n;
        if (n==4) return 4;
        return 3*cut(n-3);
    }
};


int main(){
    Solution s;
    int x= s.cuttingRope(6);
    return 0;
}
