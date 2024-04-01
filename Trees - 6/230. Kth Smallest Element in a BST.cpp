 vector<int> v;
    void inorder(TreeNode* root){
        if(root!=NULL){
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        return v[k-1];
    }
