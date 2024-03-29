 vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> v;
        map<int,int> mp;
        queue<pair<Node *,int>> q;
        q.push({root,0});
        while(q.empty()==false)
        {
            auto p=q.front();
            Node* curr=p.first;
            int hd=p.second;
            if(mp.find(hd)==mp.end())
              mp[hd]=curr->data;
            q.pop();
            if(curr->left!=NULL)
              q.push({curr->left,hd-1});
             if(curr->right!=NULL)
              q.push({curr->right,hd+1});
        }
        for(auto i:mp)
          v.push_back(i.second);
        return v;
    }
