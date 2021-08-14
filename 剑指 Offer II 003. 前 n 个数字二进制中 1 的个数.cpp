#include "headers.h"
using namespace std;

class Solution {
   public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            int tmp = i;
            while (tmp > 0) {
                res[i]++;
                tmp &= tmp - 1;
            }
        }
        return res;
    }
};