#include "headers.h"

struct f {
    int val;
    int freq;
    bool operator<(const f& a) const { return freq > a.freq; }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequent;
        for (auto& n : nums) frequent[n]++;
        priority_queue<f> pq;
        for (auto it = frequent.begin(); it != frequent.end(); ++it) {
            if (pq.size() < k)
                pq.push({it->first, it->second});
            else if (pq.top().freq < it->second) {
                pq.pop();
                pq.push({it->first, it->second});
            }
        }
        vector<int> res;
        while (!pq.empty()) {
            res.push_back(pq.top().val);
            pq.pop();
        }
        return res;
    }
};