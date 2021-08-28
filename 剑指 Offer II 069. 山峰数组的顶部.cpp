#include "headers.h"

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1;
        while (lo < hi) {
            int mi = (lo + hi) >> 1;
            if (arr[mi] > arr[mi - 1] && arr[mi] > arr[mi + 1])
                return mi;
            else if (arr[mi] > arr[mi - 1])
                lo = mi + 1;
            else if (arr[mi] > arr[mi + 1])
                hi = mi;
        }
        return -1;
    }
};