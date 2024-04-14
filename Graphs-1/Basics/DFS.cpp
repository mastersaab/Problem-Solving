 void dfs(int node,vector<int> adj[],vector<int>&visited,vector<int>& ans){
        visited[node]=1;
        ans.push_back(node);
        for(auto it:adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>visited(V,0);
        int start=0;
        vector<int>ans;
        dfs(start,adj,visited,ans);
        return ans;
    }
