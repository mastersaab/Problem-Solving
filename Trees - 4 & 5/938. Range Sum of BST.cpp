void getsum(TreeNode* root, int low, int high,int& sum){
        if(root==NULL) return;
        if(root->val>=low && root->val<=high) {sum+=root->val;}
        getsum(root->left,low,high,sum);
        getsum(root->right,low,high,sum);
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;
        getsum(root,low,high,sum);
        return sum;
    }
