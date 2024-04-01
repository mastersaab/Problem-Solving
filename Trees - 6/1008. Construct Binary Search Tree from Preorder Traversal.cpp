    TreeNode* bstFromPreorder(vector<int>& preorder) {
                int idx = 0;
                return build(preorder,idx,INT_MAX);
            }

    TreeNode* build(vector<int>& A, int& i, int upBound){
        if(i == A.size() || A[i] > upBound) return nullptr;

        TreeNode* node = new TreeNode(A[i++]);
        node->left = build(A, i, node->val);
        node->right = build(A,i, upBound);
        return node; 
    }
