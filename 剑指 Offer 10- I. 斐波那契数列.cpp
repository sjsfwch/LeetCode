#include "headers.h"

class Solution {
   public:
    int fib(int n) {
        int a = 0, b = 1;
        if (n == 0)
            return a;
        else if (n == 1)
            return b;
        for (int i = 2; i <= n; ++i) {
            int tmp = b;
            b += a;
            a = tmp;
            a %= 1000000007;
            b %= 1000000007;
        }
        return b;
    }
};