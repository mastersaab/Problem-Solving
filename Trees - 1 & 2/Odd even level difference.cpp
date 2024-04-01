int getLevelDiff(Node *root)
    { int ans=0;int i=-1;
       //Your code here
       if(root==NULL)return 0;
       queue<Node*> q;
       q.push(root);
       while(q.empty()==false)
       {  i++;
           vector<int> v;
           int count=q.size();
          for(int i=0;i<count;i++)
          {
              Node* curr=q.front();
              q.pop();
              v.push_back(curr->data);
              if(curr->left!=NULL)
                q.push(curr->left);
              if(curr->right!=NULL)
                q.push(curr->right);
          }
          int sum=accumulate(v.begin(),v.end(),0);
          if(i%2==0)
            ans+=sum;
        else
          ans-=sum;
       }
       return ans;
    }
