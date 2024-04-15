class Solution {
public:
    bool bfsOfGraph(int V, vector<vector<int>>adj,int source,int destination) {
        // Code here
        vector<int> vis(V, 0);
        queue<int>q;
        q.push(source);
        vis[source]=1;
        //vector<int>bfs;
        bool found = false;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        //bfs.push_back(node);
        if(node == destination) {
            found = true;
        }
        for(auto it:adj[node]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
    }
    return found;
    }
    vector<vector<int>> printGraph(int V, vector<vector<int>>edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
             int u=edges[i][0];
             int v=edges[i][1];
             adj[u].push_back(v);
             adj[v].push_back(u);
        }
       return adj;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1) return true;
        vector<vector<int>>adj(n);
        adj=printGraph(n,edges);
        return bfsOfGraph(n,adj,source,destination);
    }
};
