 bool dfs(int node,vector<int>&vis,vector<int>&dfsvis, vector<int> adj[]){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i]){
                bool check =dfs(i,vis,dfsvis,adj);
                if(check) return true;
            }
            else if(dfsvis[i]){
                return true;
            }
        }
        dfsvis[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>dfsvis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,dfsvis,adj)) return true;
            }
        }
        return false;
    }
