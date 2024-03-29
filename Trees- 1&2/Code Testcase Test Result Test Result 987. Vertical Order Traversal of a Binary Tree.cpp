vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)return ans;
       map<int,map<int,multiset<int>>> mp;
       queue<pair<TreeNode*,pair<int,int>>> q;
       q.push({root,{0,0}});
       while(q.empty()==false)
       {
        auto p=q.front();
       
        TreeNode* curr=p.first;
        int x=p.second.first;
        int y=p.second.second;
        mp[x][y].insert(curr->val);
        q.pop();
        if(curr->left!=NULL)
          q.push({curr->left,{x-1,y+1}});
        if(curr->right!=NULL)
         q.push({curr->right,{x+1,y+1}});
       }
       for(auto i:mp)
       {
        vector<int> v;
        for(auto j:i.second)
        {
            v.insert(v.end(),j.second.begin(),j.second.end());
        }
        ans.push_back(v);
       }
       return ans;

    }
