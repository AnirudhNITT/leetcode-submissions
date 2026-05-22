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
    
    int goodNodes(TreeNode* root,int maxval=INT_MIN) {
        
        if (root==nullptr)return 0;
        
        else{
            
            if(maxval<=root->val){
                
                maxval=root->val;
                return 1+(goodNodes(root->left,maxval)+goodNodes(root->right,maxval));
               
            }
            else{
                return(goodNodes(root->left,maxval)+goodNodes(root->right,maxval));
            }
        }
    }
};

