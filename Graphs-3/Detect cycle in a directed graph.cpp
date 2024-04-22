 bool dfs(int start,vector<int> adj[],vector<int>&vis,vector<int>&pathvis){
        vis[start]=1;
        pathvis[start]=1;
        // int n=adj.size();
        for(auto neigh:adj[start]){
            if(!vis[neigh]){
                if(dfs(neigh,adj,vis,pathvis)==true) return true;
            }
          // agar vis aur pathvis dono true hnn to cycle present h
            if(pathvis[neigh]==1) return true;   
         }
        // wapas jate waqt pathvis 0 bna do kyuki wo path to cover hi ho gya h
        // dobara agar mila to mtlb cycle present h
         pathvis[start]=0;
         return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
    vector<int>vis(V,0);
    vector<int>pathvis(V,0);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,pathvis)==true) return true;
        }
    }
    return false;
    }
