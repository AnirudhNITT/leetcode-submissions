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
    int weight_node(TreeNode* node){
        if(node==NULL)return 0;
        return max(weight_node(node->left),weight_node(node->right))+1;
    }
    bool isBalanced(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL)return true;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(abs(weight_node(curr->left)-weight_node(curr->right))>1)return false;
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
            q.pop();
        }
        return true;
    }
};
