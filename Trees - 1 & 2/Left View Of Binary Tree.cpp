void sideview(BinaryTreeNode<int>* root,vector<int>& ans,int level){
    if(root==NULL) return;
    if(level==ans.size())  ans.push_back(root->data);
    sideview(root->left,ans,level+1);
    sideview(root->right,ans,level+1);
}
vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int>ans;
    sideview(root,ans,0);
    return ans;
}
