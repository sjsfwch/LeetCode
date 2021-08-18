/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";
        unordered_map<char, int> need;
        for (auto c : t) {
            if (need.find(c) == need.end())
                need[c] = 1;
            else
                need[c]++;
        }
        int i = 0, j = 0, minj = s.size() + 1, mini = -1;
        bool flag = false;
        while (j < s.size()) {
            // 没彻底包含t
            if (!flag) {
                if (need.find(s[j]) != need.end()) need[s[j]]--;
                j++;
            } else {
                if (need.find(s[i]) != need.end()) need[s[i]]++;
                i++;
            }
            flag = check_satisfy(need);
            // 只有满足才进行最小判断
            if (flag) {
                if (j - i < minj - mini) {
                    minj = j;
                    mini = i;
                }
            }
        }
        // 继续收缩
        while (check_satisfy(need) && i < j) {
            if (j - i < minj - mini) {
                minj = j;
                mini = i;
            }
            if (need.find(s[i]) != need.end()) need[s[i]]++;
            i++;
        }
        if (mini == -1 || minj == s.size() + 1) return "";
        return s.substr(mini, minj - mini);
    }
    bool check_satisfy(unordered_map<char, int>& need) {
        for (auto it : need) {
            if (it.second > 0) return false;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution t;
    cout << t.minWindow("aa", "aa");
    return 0;
}