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

class Codec {
public:

    // Encodes a tree to a single string.
    void dfs(TreeNode* root,vector<string>&ans){
        if(root==NULL)ans.push_back("N");
        else{
            ans.push_back(to_string(root->val));
            dfs(root->left,ans);
            dfs(root->right,ans);
        }
    }
    string serialize(TreeNode* root) {
        vector<string>req;
        string str;
        dfs(root,req);
        for(int i=0;i<req.size();i++){
            
            str+=req[i];
            str.push_back('#');
        }
        
        return str;
    }
    TreeNode* buildTree(vector<string>&arr,int &i){
        if(i>=arr.size())return NULL;
        if(arr[i]=="N"){
            i++;
            return NULL;
        }
        else{
            TreeNode* node=new TreeNode(stoi(arr[i])) ;
            i++;
            node->left=buildTree(arr,i);
            node->right=buildTree(arr,i);
            return node;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>arr;
        string temp="";
        for(int i=0;i<data.size();i++){
            
            if(data[i]=='#'){
                arr.push_back(temp);
                temp="";
            }
            else{
                temp+=data[i];
            }
        }
        int i=0;
        return buildTree(arr,i);
    }
};
