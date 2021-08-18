#include "headers.h"
using namespace std;

class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int lo = 0, hi = numbers.size() - 1;
        while (lo < hi) {
            if (numbers[lo] + numbers[hi] > target)
                hi--;
            else if (numbers[lo] + numbers[hi] < target)
                lo++;
            else
                return vector<int>({lo, hi});
        }
        return vector<int>({-1, -1});
    }
};