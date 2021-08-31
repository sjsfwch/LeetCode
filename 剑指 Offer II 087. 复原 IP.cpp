#include "headers.h"

class Solution {
   private:
    vector<string> ans;
    vector<int> path;
    void recur(string &s, int begin, int index) {
        if (index == 4) {
            if (begin == s.length()) {  //字符串到达末尾，ip地址正好有4个整数
                string tmp;
                for (int i = 0; i < 3; ++i) {
                    tmp += to_string(path[i]);
                    tmp.push_back('.');
                }
                tmp += to_string(path[3]);
                ans.push_back(tmp);

            }  // else {} //字符串没有到达末尾，ip地址就有4个整数
            return;
        }

        if (begin == s.length()) {  //字符串到达末尾，ip地址不足4个整数
            return;
        }

        if (s[begin] == '0') {  //当前数字以0开始
            path.push_back(0);
            recur(s, begin + 1, index + 1);
            path.pop_back();
            return;
        }

        for (int i = begin, j = 0; i < s.length(); ++i) {
            j = j * 10 + (s[i] - '0');
            if (j >= 0 && j <= 255) {  //整数满足要求
                path.push_back(j);
                recur(s, i + 1, index + 1);
                path.pop_back();
            } else {  //整数不满足要求
                break;  //为什么此处break,因为再往后搜索，一定也是不满足要求
            }
        }
    }

   public:
    vector<string> restoreIpAddresses(string s) {
        recur(s, 0, 0);
        return ans;
    }
};