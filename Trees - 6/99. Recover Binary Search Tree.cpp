APPROACH -1->
    
void inorder(TreeNode* root,TreeNode*& prev,TreeNode*& first,TreeNode*& end)
    {
        if(root == NULL) return;
        
            inorder(root->left,prev,first,end);
            if(prev){
                if(root->val<prev->val){
                    if (!first) {
                        first = prev;
                    }
                    end=root;
                }
            } 
            prev=root;
            inorder(root->right,prev,first,end);
        
    }
    void recoverTree(TreeNode* root) {
       TreeNode* prev=NULL,*first=NULL,*end=NULL;
       inorder(root,prev,first,end);
       swap(first->val,end->val); 
       return;
    }    


APPROACH -2->
    
class Solution {
    vector<int> v{};
    void inorder(TreeNode* root)
    {
        if(root != NULL)
        {
            inorder(root->left);
            v.push_back(root->val);
            inorder(root->right);
        }
    }
    void check(TreeNode* root)
    {
        if(root != NULL)
        {
            check(root->left);
            if(root->val != v.back())
            {
                root->val = v.back();
            }
            v.pop_back();
            check(root->right);
        }
    }
public:
    void recoverTree(TreeNode* root) {
       inorder(root);
       sort(v.begin(), v.end());
       check(root);

    }
};
