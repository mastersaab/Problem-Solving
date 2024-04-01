 Node* prev=NULL;
    Node* head=NULL;
    void inorder(Node* root){
        if(root==NULL) return;
        inorder(root->left);
        if(head==NULL) head=root;
        else{
            root->left=prev;
            prev->right=root;
        }
        prev=root;
        bTreeToCList(root->right);
    }
    Node *bTreeToCList(Node *root)
    {
    //add code here.
        
        inorder(root);
        head->left=prev;
        prev->right=head;
    }
