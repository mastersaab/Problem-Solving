 int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        // check 4 directions array
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            // reached condition
            if(row==n-1 && col==m-1) return diff;
            // check 4 directions
            for(int i=0;i<4;i++){
                int newr =row-dr[i];
                int newc=col-dc[i];
                // check boundations
                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    // har node ke padosi se diff compare kro aur max store kr lo 
                    int newEffort=max(abs(heights[row][col]-heights[newr][newc]),diff);
                    // agr km aaye to dist update kro aur pq me daal do
                    if(newEffort<dist[newr][newc]){
                        dist[newr][newc]=newEffort;
                        pq.push({newEffort,{newr,newc}});
                    }
                }
            }
        }
        // unreachable
        return 0;
    }
