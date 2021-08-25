#include "headers.h"

class Solution {
   public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<int, TreeNode*>> tmp;
        auto res = root;
        int cur = -1;
        tmp.push(make_pair(0, root));
        while (!tmp.empty()) {
            auto p = tmp.front();
            tmp.pop();
            if (cur < p.first) {
                res = p.second;
                cur++;
            }
            if (p.second->left) tmp.push(make_pair(cur + 1, p.second->left));
            if (p.second->right) tmp.push(make_pair(cur + 1, p.second->right));
        }
        return res->val;
    }
};