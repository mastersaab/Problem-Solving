TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;
        if(p->val<root->val && q->val<root->val)
            return lowestCommonAncestor(root->left,p,q);
        else if(p->val>root->val && q->val>root->val)
            return lowestCommonAncestor(root->right,p,q);
        return root;
    }
