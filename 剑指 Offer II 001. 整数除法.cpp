#include "headers.h"
using namespace std;

class Solution {
   public:
    int divide(int a, int b) {
        long res = divide(long(a), long(b));
        if (res < INT32_MIN)
            return INT32_MIN;
        else if (res > INT32_MAX)
            return INT32_MAX;
        else
            return int(res);
    }
    long divide(long a, long b) {
        if (a < 0 && b < 0)
            return divide(-a, -b);
        else if (a < 0 || b < 0)
            return -divide(abs(a), abs(b));
        if (a < b) return 0;
        long base = b, quo = 1;
        while (base <= a) {
            base <<= 1;
            quo <<= 1;
        }
        long res = 0;
        while (a >= b && base >= b) {
            if (a >= base) {
                a -= base;
                res += quo;
            }
            base >>= 1;
            quo >>= 1;
        }
        return res;
    }
};

int main() {
    Solution t;
    t.divide(1000000, 2);
    return 0;
}