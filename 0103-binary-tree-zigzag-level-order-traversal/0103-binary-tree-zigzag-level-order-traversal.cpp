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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> v;
        vector<int> lvl[20001];
        queue<pair<TreeNode*,int>> q;
        if(root==NULL){
            return v;
        }
        v.push_back({root->val});
        q.push({root,0});
        int height=0;
        while(!q.empty()){
           // vector<int> temp;
            TreeNode* node=q.front().first;
            int curr=q.front().second;
          //  cout<<node->val<<" ";
            q.pop();
            if(node->left!=NULL){
                q.push({node->left,curr+1});
                lvl[curr+1].push_back(node->left->val);
            }
             if(node->right!=NULL){
                q.push({node->right,curr+1});
                 lvl[curr+1].push_back(node->right->val);
            }
            if(q.empty()){
                height=curr;
            }
           
        }
        cout<<height;
        for(int i=0;i<height+1;i++){
            if(lvl[i].size()!=0){
                if(i%2!=0){
                reverse(lvl[i].begin(),lvl[i].end());
                
            }
            v.push_back(lvl[i]); 
            }
           
        }
        return v;
        
    }
};