   int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector <vector <vector<int>>> adj(n+1);
            // 0 matlab seedha rasta
            // 1 matlb ulta rasta
            for(auto edge:edges){
                adj[edge[0]].push_back({edge[1],0});
                adj[edge[1]].push_back({edge[0],1});
            }
            
            priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            // <pair<int,int> mtlb kis type ka vl store h
            // vector<pair<int,int>> value store krne k liye
            // greater<pair<int,int>> as a comparator bdi val nikalne k liye
            pq.push({0,src});
            
            vector<int>vis(n+1);
            
            while(!pq.empty()){
                int cost = pq.top().first;
                int node = pq.top().second;
                pq.pop();
                if(node == dst) return cost;
                // for removing heirarchy
                if(vis[node]) continue;
                // if(!vis) wala case
                vis[node] = 1;
                for(auto neigh:adj[node]){
                    int nextnode = neigh[0];
                    int newcost = cost+neigh[1];
                    if(!vis[nextnode])
                        pq.push({newcost,nextnode});
                }
            }
            return -1;
        }
