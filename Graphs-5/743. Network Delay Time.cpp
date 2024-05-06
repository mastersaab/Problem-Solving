int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto &edge:times){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>result(n+1,INT_MAX); //1 se start ho rhi nodes
        result[k]=0;
        pq.push({0,k}); //time,strating node
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &neigh: adj[node]){
                int adjNode=neigh.first;
                int adjDist=neigh.second;
                if(dist+adjDist < result[adjNode]){ //same as dijkstra
                    result[adjNode]=dist+adjDist;
                    pq.push({dist+adjDist,adjNode});
                }
            }
        }
        // res array me store max val hi hmara ans h
        int ans=INT_MIN;  
        for(int i=1;i<=n;i++){
            ans=max(ans,result[i]);
        }
        // mtlb node unreachable h
        if(ans==INT_MAX) return -1;
        else return ans;
    }
