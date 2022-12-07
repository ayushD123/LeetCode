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
    //  TreeNode* ddfs(TreeNode* root,TreeNode* temp){
    //     if(root->left==NULL){
    //         return return ;
    //     }
    //     dfs(root->left,temp);
    //     temp->right=root;
    //     dfs(root->left,temp);
    // }
   void dfs(TreeNode* root,vector<int> &v){
        if(root==NULL){
            return;
        }
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        dfs(root,v);
        TreeNode* ans = new TreeNode();
         TreeNode* temp = ans;
for(auto it:v ){
    cout<<it<<" ";
    ans->right=  new TreeNode(it);
    ans=ans->right;
}
        return temp->right;
    }
};