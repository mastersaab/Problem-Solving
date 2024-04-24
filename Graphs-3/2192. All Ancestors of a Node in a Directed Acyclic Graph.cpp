void dfs(int start,vector<int>&vis,vector<vector<int>>&adj){
        vis[start]=1;
        for(auto neigh:adj[start]){
            if(vis[neigh]) continue;
            dfs(neigh,vis,adj);
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
      vector<vector<int>>adj(n);
      for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
      }

      vector<vector<int>>ans(n);

      for(int i=0;i<n;i++){
        vector<int>vis(n,0);
        dfs(i,vis,adj);
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(vis[j]) ans[j].push_back(i);
        }
      }
      return ans;
    }
