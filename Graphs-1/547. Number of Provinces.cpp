vector<vector<int>> printGraph(int V, vector<vector<int>>edges) {
        // Code here
        int n=edges.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && edges[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
       return adj;
    }
    void  dfs(int node,vector<vector<int>>adj,vector<int>&visited){
        visited[node]=1;
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited); 
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>>adj;
        int V=isConnected.size();
        adj=printGraph(V,isConnected);
        vector<int>visited(V,0);
        int count =0;
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                count++;
                dfs(i,adj,visited);
            }
        }
        return count;
    }
