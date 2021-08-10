/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include "headers.h"
// @lc code=start

bool isValid(const string& s1, const string& s2) {
    // if (s1.size() != s2.size()) return false;
    bool flag = true;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            if (flag)
                flag = false;
            else
                return false;
        }
    }
    return !(flag);
}

class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        bool flag = true;
        for (auto& w : wordList) {
            if (w == endWord) {
                flag = false;
                break;
            }
        }
        if (flag) return false;
        unordered_set<string> wordList2(wordList.begin(), wordList.end()),
            nextCur;
        nextCur.insert(beginWord);
        int minLen = bfs(nextCur, endWord, wordList2, 1);
        return minLen;
    }

    int bfs(unordered_set<string>& curWords, string& endWord,
            unordered_set<string>& wordList, int len) {
        unordered_set<string> nextCur;
        for (auto curIt = curWords.begin(); curIt != curWords.end(); ++curIt) {
            for (auto it = wordList.begin(); it != wordList.end();) {
                if (isValid(*curIt, *it)) {
                    if (*it == endWord) return len + 1;
                    nextCur.insert(*it);
                    wordList.erase(it++);
                } else
                    it++;
            }
        }
        if (nextCur.empty()) return 0;
        auto minLen = bfs(nextCur, endWord, wordList, len + 1);
        return minLen > 0 ? minLen : 0;
    }
};
// @lc code=end

int main() {
    vector<string> wl = {"hot", "dog"};
    Solution t;
    t.ladderLength("hot", "dog", wl);
}
