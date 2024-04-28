 int findShortestCycle(int n, vector<vector<int>>& edges) {
        // adjacency matrix bna lo
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        // ans inf se initialise krenge agr nhi aaya cycle to -1 return rne ke liye;
        int ans=INT_MAX;
        // har node ke liye bfs call kro starting from 0
        for(int i=0;i<n;i++){
            // dist arr tumhara starting se leke ant tk ka dist nikalegi
            vector<int>dist(n,INT_MAX);
            // parent vector har node ka parent store krega
            vector<int>parent(n,-1);
            // bfs call k liye
            dist[i]=0;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(auto neigh:adj[node]){
                    // agr vis nhi h mtlb dist inf h to dist ko ek bdha do aur parent update kr do
                    if(dist[neigh]==INT_MAX){
                        dist[neigh]=dist[node]+1;
                        parent[neigh]=node;
                        q.push(neigh);
                    }
                    // agr visit krte huye hum aisi jagh phuch gye jhan na to neigh ka parent node hai aur wo already vis h
                    else if(dist[neigh]!=INT_MAX &&  parent[node]!=neigh && parent[neigh]!=node){
                        ans=min(ans,dist[neigh]+dist[node]+1);
                    }
                }
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
