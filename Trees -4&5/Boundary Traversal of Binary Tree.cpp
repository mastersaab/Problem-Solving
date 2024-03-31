void printleaves(TreeNode<int> *root,vector<int>&v){
    if(root==NULL) return;
    printleaves(root->left,v);
    if(!(root->left)&&!(root->right)) v.push_back(root->data);
    printleaves(root->right,v);
}
void printleft(TreeNode<int> *root,vector<int>&v){
    if(root==NULL) return;
    if(root->left){
        v.push_back(root->data);
        printleft(root->left,v);
    }
    else if(root->right){
        v.push_back(root->data);
         printleft(root->right,v);
    }
}
void printright(TreeNode<int> *root,vector<int>&v){
     if(root==NULL) return;
     if(root->right){
         printright(root->right,v);
        v.push_back(root->data);
     }
     else if(root->left){
         printright(root->left,v);
         v.push_back(root->data);
     }
}
void printboundary(TreeNode<int> *root,vector<int>&v){
    if(root==NULL) return;
    v.push_back(root->data);
    printleft(root->left,v);
    printleaves(root->left,v);
    printleaves(root->right,v);
    printright(root->right,v);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	// Write your code here.
    vector<int>v;
    printboundary(root,v);
    return v;
}
