string serialize(TreeNode* root) {
     if(root ==NULL)return "";
     string s="";
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty())
     {
        TreeNode* curr=q.front();
        q.pop();
        if(curr==NULL)
          s.append("#,");
        else
        {
            s.append(to_string(curr->val)+',');
        }
         if(curr!=NULL) {  q.push(curr->left);
            q.push(curr->right);}
        
     }   
     return s;
    }

    
    TreeNode* deserialize(string data) {
     if(data.size()==0)return NULL;
     stringstream s(data);
     string str;
     getline(s,str,',');
     TreeNode* root=new TreeNode(stoi(str));
     queue<TreeNode*> q;
     q.push(root);
     while(!q.empty())
     {
       TreeNode* curr=q.front();
       q.pop();
       getline(s,str,',');
       if(str=="#")
        curr->left=NULL;
       else
       {
         TreeNode* leftNode=new TreeNode(stoi(str));
         curr->left=leftNode;
         q.push(leftNode);
       }
       getline(s,str,',');
       if(str=="#")
        curr->right=NULL;
        else
        {
           TreeNode* rightNode=new TreeNode(stoi(str));
         curr->right=rightNode;
         q.push(rightNode); 
        }
     } 
return root;
}
