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
    long long ans=0;
    long long sum=0;
    int mod=1e9+7;
    // void dfs(TreeNode* root){
    //     if(root==NULL){
    //         return;
    //     }
    //     sum+=root->val;
    //     dfs(root->left);
    //     dfs(root->right);
    // }
    
    long long maxsum(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        long long cursum=maxsum(root->left)+maxsum(root->right)+(root->val);
        ans=max(ans,(sum-cursum)*cursum);
        return cursum;
    }
    
    int maxProduct(TreeNode* root) {
        
        // dfs(root);
        // cout<<sum;
        //vector<intcur> prod;
        sum=maxsum(root);
        maxsum(root);
        return ans%mod;
    }
};