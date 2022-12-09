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
    void dfs(TreeNode* root,int max,int min,vector<int> &v){
        if(root==NULL){
            v.push_back(abs(max-min));
            return;
        }
        int valu=root->val;
        if(valu>max){
            max=valu;
        }
        if(valu<min){
            min=valu;
        }
        dfs(root->left,max,min,v);
         dfs(root->right,max,min,v);
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<int> v;
        dfs(root,0,99999,v);
        return *max_element(v.begin(),v.end());
    }
};