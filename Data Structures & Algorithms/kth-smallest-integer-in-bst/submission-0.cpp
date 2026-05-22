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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        TreeNode*curr=root;
        int result;
        int num=0;
        while((curr!=nullptr||!st.empty())&&num<k){
            while(curr!=nullptr){
            st.push(curr);
            curr=curr->left;
            }
            curr=st.top();
            st.pop();
            result=curr->val;
            curr=curr->right;
            num++;
        }
    return result;
    }
};
