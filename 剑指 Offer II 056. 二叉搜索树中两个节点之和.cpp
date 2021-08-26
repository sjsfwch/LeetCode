#include "headers.h"

class Solution {
   public:
    bool findTarget(TreeNode* root, int k) {
        vector<TreeNode*> _bst;
        dfs(root, _bst);
        int lo = 0, hi = _bst.size() - 1;
        while (lo < hi) {
            if (_bst[lo]->val + _bst[hi]->val > k)
                hi--;
            else if (_bst[lo]->val + _bst[hi]->val < k)
                lo++;
            else
                return true;
        }
        return false;
    }
    void dfs(TreeNode* root, vector<TreeNode*>& _bst) {
        if (!root) return;
        dfs(root->left, _bst);
        _bst.push_back(root);
        dfs(root->right, _bst);
    }
};