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
    TreeNode* delete_node(TreeNode* root,int target){
        if(root==NULL)return root;
        root->left= delete_node(root->left,target);
        root->right= delete_node(root->right,target);
        if(root->left==NULL && root->right==NULL && root->val==target){
            root=NULL;
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return delete_node(root,target);
        
    }
};