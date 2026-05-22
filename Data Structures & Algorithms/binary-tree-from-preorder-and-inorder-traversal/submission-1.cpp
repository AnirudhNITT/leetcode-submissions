/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)return NULL;
        int mid=0;
       TreeNode* root = new TreeNode(preorder[0]);
        for(int i=0;i<inorder.size();i++){
            if (inorder[i]==preorder[0]) mid=i;
        }
        vector<int>preLeft(preorder.begin()+1,preorder.begin()+mid+1);
        vector<int>preright(preorder.begin()+mid+1,preorder.end());
        vector<int>inLeft(inorder.begin(),inorder.begin()+mid);
        vector<int>inRight(inorder.begin()+mid+1,inorder.end());
        root->left=buildTree(preLeft,inLeft);
        root->right=buildTree(preright,inRight);
        return root;
    }
};
