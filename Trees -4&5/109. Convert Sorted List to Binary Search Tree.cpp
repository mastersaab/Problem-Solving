TreeNode* BST(vector<int>& v){
    if(v.size()==0) return NULL;
    if(v.size()==1) return new TreeNode(v[0]);

    int mid = v.size()/2;
    TreeNode* root= new TreeNode(v[mid]);

    vector<int> leftTree(v.begin(),v.begin()+mid);
    vector<int> rightTree(v.begin()+mid+1,v.end());

    root->left = BST(leftTree);
    root->right = BST(rightTree);

    return root;
}

TreeNode* sortedListToBST(ListNode* head) {
    ListNode* temp=head;
    vector<int> v;
    // Converting LinkedList into array
    while(temp){
        v.emplace_back(temp->val);
        temp=temp->next;
    }
    if(v.size()==0) return NULL;
    if(v.size()==1) return new TreeNode(v[0]);
    return BST(v);
}
