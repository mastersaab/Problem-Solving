vector<vector<int>>ans;
    void inorder(TreeNode*root,int sum,int targetsum,vector<int>temp){
        if(root==NULL) return ;
        sum+=root->val;
        temp.push_back(root->val);
        if(root->left==NULL&&root->right==NULL){
            if(sum==targetsum) ans.push_back(temp);
            else return;
        }
        inorder(root->left,sum,targetsum,temp);
        inorder(root->right,sum,targetsum,temp);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>temp;
        inorder(root,sum,targetSum,temp);
        return ans;
    }
