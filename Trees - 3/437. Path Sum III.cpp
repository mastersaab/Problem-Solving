APPROACH 1-- IN n^2 SHOWING TLE
int count=0;
    vector<int>v;
    int pathSum(TreeNode* root, int targetSum) {
        getsum(root,targetSum);
        return count;
    }
    void getsum(TreeNode* root,int targetsum){
        if(root==NULL) return ;
        v.push_back(root->val);
        getsum(root->left,targetsum);
        getsum(root->right,targetsum);
        int sum=0;
        for(int i=v.size()-1;i>=0;--i){
            sum+=v[i];
            if(sum==targetsum) count++;
        }
        v.pop_back();
    }
APPROACH 2--USING MAPPING TEHCNIQUE
int count=0;
    void getsum(TreeNode* root,long long int targetsum){
        if(root==NULL) return;
        if(targetsum==root->val) count++;
        getsum(root->left,targetsum-root->val);
        getsum(root->right,targetsum-root->val);

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        getsum(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return count;
    }
