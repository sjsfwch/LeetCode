/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include "headers.h"
// @lc code=start
void split_string(const std::string &s, std::vector<int> &v,
                  const std::string &c) {
    std::string::size_type pos1, pos2;
    pos2 = s.find(c);
    pos1 = 0;
    while (std::string::npos != pos2) {
        v.push_back(stoi(s.substr(pos1, pos2 - pos1)));

        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
    }
    if (pos1 != s.length()) v.push_back(stoi(s.substr(pos1)));
}
class Solution {
   public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        split_string(version1, v1, ".");
        split_string(version2, v2, ".");
        while (v1.size() < v2.size()) v1.push_back(0);
        while (v2.size() < v1.size()) v2.push_back(0);
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] > v2[i])
                return 1;
            else if (v1[i] < v2[i])
                return -1;
        }
        return 0;
    }
};
// @lc code=end
