Node* LCA(Node* root,int a,int b){
        if(root==NULL) return NULL;
        if(root->data==a||root->data==b) return root;
        Node* left=LCA(root->left,a,b);
        Node* right=LCA(root->right,a,b);
        if(left!=NULL&&right!=NULL) return root;
        if(left) return left;
        return right;
    }
    int dist(Node* root,int val){
        if(root==NULL) return 0;
        if(root->data==val) return 1;
        int left=dist(root->left,val);
        int right=dist(root->right,val);
        if(!left and !right) return 0;
        else return left+right+1;
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        Node*lca= LCA(root,a,b);
        int x=dist(lca,a);
        int y=dist(lca,b);
        return x+y-2;
    }
