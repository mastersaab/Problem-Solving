bool isValidBST(TreeNode* root) {
        return isValid(root,LLONG_MIN,LLONG_MAX);
    }
bool isValid(TreeNode* root,long long min,long long max){
    if(root==NULL) return true;
    if(min>=root->val||root->val>=max) return false;
    return isValid(root->left,min,root->val)&& isValid(root->right,root->val,max);
}
