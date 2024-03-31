bool flag=false;
    void inorder(TreeNode* root,int targetsum,int sum){
        if(root==NULL) return ;
        sum+=root->val;
        if(targetsum==sum && root->left==NULL && root->right==NULL){
                flag=true;
                return;
        }
        inorder(root->left,targetsum,sum);
        inorder(root->right,targetsum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        inorder(root,targetSum,0);
        return flag;
    }
