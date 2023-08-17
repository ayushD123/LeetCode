class Solution {
public:
    void dfs(TreeNode* curr, TreeNode* parn, unordered_map<TreeNode*, int>& depth, unordered_map<TreeNode*, TreeNode*>& par) {
        if (curr == NULL) return;
        par[curr] = parn;
        depth[curr] = depth[parn] + 1;
        dfs(curr->left, curr, depth, par);
        dfs(curr->right, curr, depth, par);
    }
    
    TreeNode* lca(TreeNode* p, TreeNode* q, unordered_map<TreeNode*, int>& depth, unordered_map<TreeNode*, TreeNode*>& par) {
        if (depth[p] < depth[q]) swap(p, q);
        int diff = depth[p] - depth[q];
        while (diff--) {
            p = par[p];
        }
        while (p->val != q->val) {
            p = par[p];
            q = par[q];
        }
        return p;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, int> depth;
        unordered_map<TreeNode*, TreeNode*> par;
        depth[NULL] = 0; // Set depth of NULL to -1
        dfs(root, NULL, depth, par);
        return lca(p, q, depth, par);
    }
};
