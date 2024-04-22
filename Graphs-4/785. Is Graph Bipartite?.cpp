bool ischeck(int start,vector<vector<int>>&graph,vector<int>&color){
        color[start]=0;
        queue<int>q;
        q.push(start);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neigh:graph[node]){
                if(color[neigh]==-1){
                    color[neigh]=!color[node];
                    q.push(neigh);
                }
                else if(color[neigh]==color[node]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        // vector<vector<int>>adj(n);
        // for (auto& edge : graph) {
        // int u = edge[0];
        // int v = edge[1];
        // adj[u].push_back(v);
        // adj[v].push_back(u);
        // }
        vector<int>color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(ischeck(i,graph,color)==false ) return false;
            }
        }
        return true;
    }
