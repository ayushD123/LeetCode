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
    TreeNode* helper(TreeNode* node){
        if(node==NULL) return NULL;
        if(node->right==NULL) return node;
        return helper(node->right);
    }
    TreeNode* solve(TreeNode* node,int key){
        if(node==NULL){
            return NULL;
        }
        if(node->val==key){
            if(node->left==NULL && node->right==NULL){
                return NULL;
            }
            if(node->left==NULL) return node->right;
            if(node->right==NULL) return node->left;
            int data= helper(node->left)->val;
            node->val=data;
            node->left=solve(node->left,data);
            return node;
            
        }
        if(node->val>key){
            node->left= solve(node->left,key);
        }else{
            node->right= solve(node->right,key);
        }
        return node;
    
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
    }
};