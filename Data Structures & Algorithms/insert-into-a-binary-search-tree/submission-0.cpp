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
    void find_node(TreeNode* root,int val){
        if(root->val<val){
            if(root->right==NULL){
                root->right= new TreeNode(val);
                return;
            }
            else{
                find_node(root->right,val);
            }
        }
        else{
            if(root->left==NULL){
                root->left= new TreeNode(val);
                return;
            }
            else{
                find_node(root->left,val);
            }
        }
        return;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL)return (new TreeNode(val));
        find_node(root,val);
        return root;
    }
};