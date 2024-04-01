vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      if(root==NULL)return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(q.empty()==false)
    {
        int n=q.size();
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            
           TreeNode* curr=q.front();
           q.pop();
           v.push_back(curr->val);
           if(curr->left!=NULL)
            q.push(curr->left);
             if(curr->right!=NULL)
            q.push(curr->right);

        }
        int m=v.size();
        ans.push_back(v[m-1]);
    }
    return ans;  
}
