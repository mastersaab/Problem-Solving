int dfs(string &colors,vector<vector<int>>&adj,int ind,vector<int>&vis,vector<vector<int>>&v){
        if(!vis[ind]){
            vis[ind] = 1;
            for(auto it : adj[ind]){
                // heirarchy kam krne k liye
                if(dfs(colors,adj,it,vis,v) == INT_MAX) {
                    return INT_MAX;
                }
                for(auto i=0;i<26;i++){
                    v[ind][i] = max(v[ind][i],v[it][i]);
                }
            }
            // color ka count bdha do
            ++v[ind][colors[ind]-'a'];
            // completely visited node ko 2  kr do
            vis[ind] = 2;
        }
        // agar completely vis h to color return kr do
        if(vis[ind]==2) return v[ind][colors[ind]-'a'];
        // nhi to rec call ke liye int max
        else return INT_MAX;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        // v ek 2d vector h jo ki raste me aane wale colors ka count rkhega
        vector<vector<int>>v(n,vector<int>(26,0));
        // adj matrix bna lo
        vector<vector<int>>adj(n);
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
        }

        int ans = 0;
        vector<int>vis(n,0);
        for(int i=0;i<n && ans!=INT_MAX;i++){
            ans = max(ans,dfs(colors,adj,i,vis,v));
        }
        // agr dfs se int max aaya mtlb cycle h
        if(ans==INT_MAX) return -1;
        // nhi to ans return kr do
        return ans;
    }
