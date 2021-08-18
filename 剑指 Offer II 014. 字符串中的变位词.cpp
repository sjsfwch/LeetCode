#include "headers.h"

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s;
        for (auto& c : s1) s[c]++;
        int start = 0, end = 0, upcount = s.size();
        bool endrun = true;
        while (end < s2.size()) {
            auto tmp = s;
            upcount = s.size();
            while (end < s2.size() && start <= end) {
                auto c = endrun ? s2[end++] : s2[start++];
                if (tmp.find(c) != tmp.end()) {
                    if (endrun) {
                        tmp[c]--;
                        if (tmp[c] == 0) {
                            upcount--;
                            if (upcount == 0) return true;
                        } else if (tmp[c] < 0) {
                            endrun = false;
                        }
                    } else {
                        tmp[c]++;
                        if (tmp[c] == 1)
                            upcount++;
                        else if (tmp[c] == 0)
                            endrun = true;
                    }
                } else {
                    start = end;
                    break;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution t;
    auto flag = t.checkInclusion("ab", "eidboaoo");
    return 0;
}