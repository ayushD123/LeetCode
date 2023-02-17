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
    private:
    void dfs(vector<int> &v,TreeNode* root){
        if(root==NULL){
            return;
        }
        
        dfs(v,root->left);
        v.push_back(root->val);
        dfs(v,root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        dfs(v,root);
        int ans=1e5;
        
        for(int i=0;i<v.size()-1;++i){
          ans=min(ans,abs(v[i]-v[i+1]));
        }
        
        return ans;
        
    }
};