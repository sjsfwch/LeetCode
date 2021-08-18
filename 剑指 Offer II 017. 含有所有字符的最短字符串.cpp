#include "headers.h"

class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmp;
        for (auto &c : t) tmp[c]++;
        int res = INT32_MAX;
        int lo = 0, hi = 0, count = tmp.size();
        string resstr;
        bool flag = true;
        while (hi < s.size()) {
            auto c = flag ? s[hi++] : s[lo++];
            if (tmp.find(c) != tmp.end()) {
                if (flag) {
                    tmp[c]--;
                    if (tmp[c] == 0) {
                        count--;
                        if (count == 0) flag = false;
                    }
                } else {
                    tmp[c]++;
                    if (tmp[c] == 1) {
                        count++;
                        flag = true;
                    }
                }
            }
            if (count == 0 && hi - lo < res) {
                res = hi - lo;
                resstr = s.substr(lo, hi - lo);
            }
        }
        while (!flag && lo < hi) {
            auto c = s[lo++];
            if (tmp.find(c) != tmp.end()) {
                tmp[c]++;
                if (tmp[c] == 1) {
                    count++;
                    flag = true;
                }
            }
            if (count == 0 && hi - lo < res) {
                res = hi - lo;
                resstr = s.substr(lo, hi - lo);
            }
        }
        return resstr;
    }
};

int main() {
    Solution t;
    t.minWindow("ADOBECODEBANC", "ABC");
    return 0;
}