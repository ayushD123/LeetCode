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
    void preorder(vector<int> &ans,TreeNode* root){
    if(root==NULL){
            
            return;
        }
        
        preorder(ans,root->left);
        ans.push_back(root->val);
        preorder(ans,root->right);
        ans.push_back(0);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
       
        
        vector<int> ans1;
             vector<int> ans2;
        preorder(ans1,p);
        preorder(ans2,q);
        for(auto it:ans1){
            cout<<it<<" ";
        }
        cout<<endl;
         for(auto it:ans2){
            cout<<it<<" ";
        }
       if(ans1==ans2) return true;     
        return false;
    }
};