#include "headers.h"
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        int rootValue=preorder[0];
        int count=0;
        for(int i=0;i<inorder.size();i++){
            if (inorder[i]==rootValue) break;
            count++;
        }
        TreeNode* root=new TreeNode(preorder[0]);
        root->left=buildTreeRecurrent(preorder,1,count+1,inorder,0,count);
        root->right=buildTreeRecurrent(preorder,count+1,preorder.size(),inorder,count+1,inorder.size());
        return root;
    }

    TreeNode* buildTreeRecurrent(vector<int>& preorder,int startp,int endp,vector<int>& inorder,int starti,int endi){
        if (startp>=endp) return NULL;
        int rootValue=preorder[startp],count=0;
        for(int i=starti;i<endi;i++){
            if (inorder[i]==rootValue) break;
            count++;
        }
        TreeNode* root=new TreeNode(preorder[startp]);
        root->left=buildTreeRecurrent(preorder,startp+1,startp+count+1,inorder,starti,starti+count);
        root->right=buildTreeRecurrent(preorder,startp+count+1,endp,inorder,starti+count+1,endi);
        return root;
    }
};

int main(){
    vector<int> preorder={1,2,3},inorder={3,2,1};
    Solution s;
    auto p=s.buildTree(preorder,inorder);
    return 0;
}