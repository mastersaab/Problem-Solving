bool isPresent(TreeNode* root,int key,vector<int>& ans)
{
    if(root==NULL)
      return false;
     
    
    if((root->val==key) || (isPresent(root->left,key,ans) || isPresent(root->right,key,ans)))
    {
    ans.push_back(root->val);
        return true;
    }
       
    
    return false;

}
vector<int> Solution::solve(TreeNode* A, int B) {
   
   vector<int> ans;
   isPresent(A,B,ans);
    reverse(ans.begin(),ans.end());
    return ans;
   
}

