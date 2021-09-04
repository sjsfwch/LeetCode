#include "headers.h"

class Solution {
   public:
    vector<int> smallestK(vector<int> &arr, int k) {
        vector<int> res;
        if (k == 0) return res;
        priority_queue<int> heap;
        for (auto &n : arr) {
            if (heap.size() < k)
                heap.push(n);
            else {
                if (n < heap.top()) {
                    heap.pop();
                    heap.push(n);
                }
            }
        }

        while (!heap.empty()) {
            res.push_back(heap.top());
            heap.pop();
        }

        return res;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 2, 4, 6, 8};
    Solution t;
    t.smallestK(arr, 0);
    return 0;
}