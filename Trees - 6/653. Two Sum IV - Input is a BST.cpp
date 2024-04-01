 vector<int>v;
    void traversal(TreeNode* root){
        if(root==NULL) return;
        traversal(root->left);
        v.push_back(root->val);
        traversal(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        traversal(root);
        map<int,int>map;
        for(int i=0;i<v.size();i++){
            map.insert({i,v[i]});
        }
        for(int i=0;i<v.size();i++){
            int x=v[i];
            int target=k-x;
            for(int j=0;j<v.size();j++){
                if(v[j]==target && i!=j) return true;
            }
        }
        return false;
    }
