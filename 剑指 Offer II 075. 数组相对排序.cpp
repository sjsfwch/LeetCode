#include "headers.h"

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order;
        for (int i = 0; i < arr2.size(); ++i) order[arr2[i]] = i;
        auto cmp = [&order](const int& a, const int& b) {
            if (order.find(a) != order.end() && order.find(b) != order.end())
                return order[a] < order[b];
            else if (order.find(a) != order.end())
                return true;
            else if (order.find(b) != order.end())
                return false;
            else
                return a < b;
        };

        sort(arr1.begin(), arr1.end(), cmp);
        return arr1;
    }
};