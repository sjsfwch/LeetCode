#include "headers.h"

class Solution {
   public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = 0;
        for (auto& c : nums) res ^= c;
        return res;
    }
};