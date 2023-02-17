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
        v.push_back(root->val);
        dfs(v,root->left);
        dfs(v,root->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        dfs(v,root);
        int ans=1e5;
        for(auto it:v){
            cout<<it<<" ";
        }
        for(int i=0;i<v.size();++i){
            for(int j=i+1;j<v.size();++j){
            if(i!=j){
                ans=min(ans,abs(v[i]-v[j]));
            }
        }
        }
        
        return ans;
        
    }
};