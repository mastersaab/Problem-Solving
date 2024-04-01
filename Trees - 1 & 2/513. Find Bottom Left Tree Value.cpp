int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> ans; 
     queue<TreeNode*> q;
     if(root==NULL)
         return 0;
     q.push(root);
     while(q.empty()==false)
     {
         int count=q.size();
         vector<int> cur;
         for(int i=0;i<count;i++)
         {
             TreeNode* curr=q.front();
             q.pop();
             cur.push_back(curr->val);
             if(curr->left!=NULL)
              q.push(curr->left);
            if(curr->right!=NULL)
             q.push(curr->right);
         }
         ans.push_back(cur);
     }
     int n=ans.size();
     return ans[n-1][0];
    }
