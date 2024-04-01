int diameter(TreeNode* root,int& maxi){

    
        if(!root) return 0;
        int left=diameter(root->left,maxi);
        int right=diameter(root->right,maxi);
        maxi=max(maxi,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int d=0;
        diameter(root,d);
        return d;
    }
