/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */
#include "headers.h"
// @lc code=start
class Solution {
   public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> tmp;
        int i = 0, j = 0;
        while (i < pushed.size() && j < popped.size()) {
            if (pushed[i] != popped[j]) {
                if ((!tmp.empty()) && popped[j] == tmp.top()) {
                    j++;
                    tmp.pop();
                } else
                    tmp.push(pushed[i++]);
            } else {
                i++;
                j++;
            }
        }
        while (j < popped.size()) {
            if (popped[j] != tmp.top()) return false;
            tmp.pop();
            j++;
        }
        return true;
    }
};
// @lc code=end
int main() {
    vector<int> pushed = {2, 1, 0}, poped = {1, 2, 0};
    Solution t;
    t.validateStackSequences(pushed, poped);
    return 0;
}