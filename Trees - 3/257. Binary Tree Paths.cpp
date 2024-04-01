void preorder(TreeNode * root, vector<string>&ans, string s){
        if(root==nullptr) return; //0child
        if(root->left==nullptr && root->right==nullptr){//1child
            s+=to_string(root->val);
            ans.push_back(s);
        }
        s+=to_string(root->val);
        preorder(root->left,ans,s+"->");
        preorder(root->right,ans,s+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string>ans;
        preorder(root,ans,s);
        return ans;
    }
