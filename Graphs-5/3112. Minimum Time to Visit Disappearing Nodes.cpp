void dijkstras(int src,vector<int>&disappear,unordered_map<int,vector<pair<int,int>>>&adj,vector<int>&dis,vector<int>&vis){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src}); //{dist,src}
        while(!pq.empty()){
            // shortest dist nikal lo
            pair<int,int>best=pq.top();
            pq.pop();
            int d=best.first;
            int node=best.second;

            // agr phle se vis h ya fir best dist jyada h disappearing time se to aage bdh jaao
            if(vis[node] || d>=disappear[node]) continue;

            // nhi to update kr do
            dis[node]=d;
            vis[node]=1;
            for(auto neigh:adj[node]){
                if(vis[neigh.first]==0){
                    pq.push({d+neigh.second,neigh.first});
                }
            }
        }
    }
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int>dis(n,-1);
        vector<int>vis(n,0);
        dijkstras(0,disappear,adj,dis,vis);
        return dis;
    }
