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
  
    TreeNode* searchBST(TreeNode* node, int va) {
         if(node==NULL){
            return NULL;
        }
        if(node->val==va){
            return node;
        }
        if(node->val>va){
            return searchBST(node->left,va);
        }else{
            return searchBST(node->right,va);
        }
        
    }
};