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
    TreeNode* solve(TreeNode* node,int va){
        if(node==NULL){
            return NULL;
        }
        if(node->val==va){
            return node;
        }
        if(node->val>va){
            return solve(node->left,va);
        }else{
            return solve(node->right,va);
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
        
    }
};