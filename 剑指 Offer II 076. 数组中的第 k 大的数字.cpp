#include "headers.h"

class Solution {
   public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto& n : nums) {
            if (heap.size() < k)
                heap.push(n);
            else {
                if (n > heap.top()) {
                    heap.pop();
                    heap.push(n);
                }
            }
        }
        return heap.top();
    }
};