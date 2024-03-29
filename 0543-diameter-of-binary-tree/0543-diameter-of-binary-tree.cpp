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
    //O(Nsq)
//     int maxd=0;
//     int height(TreeNode* node){
//         if(node==NULL) return 0;
//         int l=height(node->left);
//         int r=height(node->right);
//         return 1+max(l,r);
//     }
    
//     void diam(TreeNode* node){
//         if(node==NULL) return;
//         int lh=height(node->left);
//         int rh=height(node->right);
//         maxd=max(maxd,lh+rh);
//         diam(node->left);
//         diam(node->right);
//     }
//     int diameterOfBinaryTree(TreeNode* root) {
//         diam(root);
//         return maxd;
//     }
    int heigh(TreeNode* node,int& diam){
         if(node==NULL) return 0;
        int l=heigh(node->left,diam);
        int r=heigh(node->right,diam);
        diam=max(diam,l+r);
        return 1+max(l,r);
    }
      int diameterOfBinaryTree(TreeNode* root) {
          int diam=0;
        heigh(root,diam);
        return diam;
    }
    
    
};