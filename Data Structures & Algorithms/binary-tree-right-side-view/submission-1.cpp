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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>soln;
        if(root==nullptr)return soln;
        q.push(root);
        TreeNode*curr=root;
        while(!q.empty()){
            int size=q.size();
            int curr_val;
            for(int i=0;i<size;i++){
                curr=q.front();
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                q.pop();
                }
                soln.emplace_back(curr->val);
            }
        return soln;
        
         }
    };
