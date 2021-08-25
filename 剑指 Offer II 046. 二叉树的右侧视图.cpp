#include "headers.h"

class Solution {
   public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<pair<int, TreeNode*>> tmp;
        tmp.push(make_pair(0, root));
        int cur = -1;
        while (!tmp.empty()) {
            auto p = tmp.front();
            tmp.pop();
            if (cur < p.first) {
                res.push_back(p.second->val);
                cur++;
            } else {
                res[cur] = p.second->val;
            }
            if (p.second->left) tmp.push(make_pair(cur + 1, p.second->left));
            if (p.second->right) tmp.push(make_pair(cur + 1, p.second->right));
        }
        return res;
    }
};