#include "headers.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
   private:
    vector<TreeNode*> _bst;
    int _cur;

   public:
    BSTIterator(TreeNode* root) {
        dfs(root);
        _cur = -1;
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        dfs(root->left);
        _bst.push_back(root);
        dfs(root->right);
    }

    int next() {
        _cur++;
        return _bst[_cur]->val;
    }

    bool hasNext() { return _cur + 1 < _bst.size(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */