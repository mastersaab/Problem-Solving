public:
	//Function to find number of strongly connected components in the graph.
	void dfs2(int node,vector<vector<int>>&adjT,vector<int>&vis1){
	    vis1[node]=1;
	    for(auto it:adjT[node]){
	        if(!vis1[it]){
	          dfs2(it,adjT,vis1);
	        }
	    }
	}
	void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st){
	    vis[node]=1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,adj,st);
	        }
	    }
	    st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int>vis(V,0);
        stack<int>st;
        // phle stack me ulte order me store kr lo 
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        // fir grpah ulta kr lo
        vector<vector<int>>adjT(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adjT[it].push_back(i);
            }
        }
        // ab stack se ek ek val ke liye dfs hlao dekho khan kitna connected componenet hai
        int count =0;
        vector<int>vis1(V,0);
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(!vis1[node]){
                count++;
                dfs2(node,adjT,vis1);
            }
        }
        return count;
    }
