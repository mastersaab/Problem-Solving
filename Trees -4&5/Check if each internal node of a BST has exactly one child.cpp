bool has_only_one_child(TreeNode* root){
    if(root==NULL)|| (node->left==NULL && node->right==NULL){
        return true;
    }
      if(root->left==NULL|| root->right==NULL{
          return has_only_one_child(root->left)||has_only_one_child(node->right);
   }
      return false;
}
