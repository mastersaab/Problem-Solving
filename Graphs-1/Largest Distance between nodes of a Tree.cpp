int dfs(int node,vector<vector<int>>&adj,int& ans){
    int maxi=0;
    for(auto it:adj[node]){
        int temp_height=dfs(it,adj,ans);
        ans=max(ans,maxi+temp_height);
        maxi=max(maxi,temp_height);
    }
    return 1+maxi;
}
int Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<vector<int>>adj(A.size(), vector<int>(0));
    int root=-1;
    for(int i=0;i<A.size();i++){
        if(A[i]==-1){
            root=i;
            continue;
        }
        adj[A[i]].push_back(i);
    }
    int ans=0;
    dfs(root,adj,ans);
    return ans;
}
