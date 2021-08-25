#include "headers.h"

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> tmp;
        tmp.push(root);
        while (!tmp.empty()) {
            auto node = tmp.front();
            tmp.pop();
            if (node) {
                res += to_string(node->val);
                tmp.push(node->left);
                tmp.push(node->right);
            }
            res += ',';
        }
        while (res.back() == ',') res.pop_back();
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        char sign = ',';
        int start = 0, end = 0;
        vector<TreeNode*> tmp;
        while (end < data.size()) {
            while (data[end] != sign && end < data.size()) end++;
            if (start == end)
                tmp.push_back(nullptr);
            else
                tmp.push_back(
                    new TreeNode{stoi(data.substr(start, end - start))});
            end++;
            start = end;
        }

        int rootIdx = -1, cur = 1;
        while (cur < tmp.size() && rootIdx < cur) {
            rootIdx++;
            if (!tmp[rootIdx]) continue;
            tmp[rootIdx]->left = tmp[cur];
            cur++;
            if (cur >= tmp.size()) break;
            tmp[rootIdx]->right = tmp[cur];
            cur++;
        }
        return tmp[0];
    }
};

int main() {
    Codec cd;
    auto root = cd.deserialize("1,2,3,,,4,5,6,7");
    auto s = cd.serialize(root);
    return 0;
}