#include "headers.h"

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> tmp(26, -10000);
        int count = 0;
        for (auto &c : p) {
            if (tmp[c - 'a'] < 0) {
                tmp[c - 'a'] = 0;
                count++;
            }
            tmp[c - 'a']++;
        }
        int lo = 0, hi = 0;
        while (hi < p.size()) tmp[s[hi++] - 'a']--;
        auto check = [&tmp]() {
            for (auto &n : tmp) {
                if (n == -10000) continue;
                if (n != 0) return false;
            }
            return true;
        };
        if (check()) res.push_back(lo);
        while (hi < s.size()) {
            auto loc = s[lo++] - 'a', hic = s[hi++] - 'a';
            if (tmp[loc] != -10000) tmp[loc]++;
            if (tmp[hic] != -10000) tmp[hic]--;
            if (check()) res.push_back(lo);
        }
        return res;
    }
};