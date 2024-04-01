 map<int,int>m;
    void inorder1(Node* root1){
        if(!root1) return;
        inorder1(root1->left);
        m[root1->data]=1;
        inorder1(root1->right);
        
    }
    void inorder2(Node* root2,vector<int>&ans){
        if(!root2) return;
        inorder2(root2->left,ans);
        if(m[root2->data]) ans.push_back(root2->data);
        inorder2(root2->right,ans);
        
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
     vector<int>ans;
     inorder1(root1);
     inorder2(root2,ans);
     return ans;
    }
