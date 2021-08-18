#include "headers.h"

class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int lo = 0, hi = 0, res = 0;
        long product = 1;
        while (hi < nums.size()) {
            product *= nums[hi++];
            while (lo < hi && product >= k) product /= nums[lo++];
            // 为什么求得符合情况的一种len的时候就可以 + len呢》
            // [10, 5] -> [10],  [10,5]
            // [5, 2] ->  [5], [5, 2]
            // 为了去重，我们相当于以lo为起点，依次添加一个数进可行的范围，不重不漏
            res += hi - lo;
        }
        return res;
    }
};
