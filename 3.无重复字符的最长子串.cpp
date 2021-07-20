/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "headers.h"
using namespace std;
// @lc code=start
class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        // vector<int> index(128, -1);
        int index[128];
        memset(index, -1, 128 * sizeof(int));
        int start = 0, maxLen = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (index[s[i]] >= start) {
                maxLen = max(maxLen, i - start);
                start = index[s[i]] + 1;
            }
            index[s[i]] = i;
        }
        maxLen = max(maxLen, int(s.size()) - start);

        return maxLen;
    }
};
// @lc code=end

int main() {
    Solution t;
    string input = "a";
    t.lengthOfLongestSubstring(input);
    return 0;
}
