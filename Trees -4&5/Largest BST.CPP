APPROACH 1--BY USING 4 VARIABLES/ARGURMENTS

class info{
        public:
        int maxi;
        int mini;
        bool isBST;
        int size;
    };
    info postorder(Node* root,int& ans){
        if(root==NULL) return {INT_MIN,INT_MAX,true,0};
        info left=postorder(root->left,ans);
        info right=postorder(root->right,ans);
        
        info currnode;
        
        currnode.size=left.size+right.size+1;
        currnode.maxi=max(root->data,right.maxi);
        currnode.mini=min(root->data,left.mini);
        
        if(left.isBST && right.isBST&&(root->data>left.maxi&&root->data<right.mini)) {
            currnode.isBST=true;
        }
        else currnode.isBST=false;
        if(currnode.isBST) ans=max(ans,currnode.size);
        return currnode;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	int maxsize=0;
    	info temp=postorder(root,maxsize);
    	return maxsize;
    }

APPROACH 2--USING 3 VARIABLES

  class info{
        public:
        int maxi;
        int mini;
       // bool isBST;
        int size;
    };
    info postorder(Node* root){
        if(root==NULL) return {INT_MIN,INT_MAX,0};
        info left=postorder(root->left);
        info right=postorder(root->right);
        
        info currnode;
        
      
        if(root->data>left.maxi&&root->data<right.mini) {
                currnode.size=left.size+right.size+1;
                currnode.maxi=max(root->data,right.maxi);
                currnode.mini=min(root->data,left.mini);
        }
        else{
                currnode.size=max(left.size,right.size);
                currnode.maxi=INT_MAX;
                currnode.mini=INT_MIN;
        }
        //if(currnode.isBST) ans=max(ans,currnode.size);
        return currnode;
    }
    int largestBst(Node *root)
    {
    	//Your code here
    	int maxsize=0;
    	info temp=postorder(root);
    	return temp.size;
    }
