void dfs(int start,vector<int>&vis,stack<int>&st,vector<int>adj[]){
	    vis[start]=1;
	    for(auto neigh:adj[start]){
	        if(!vis[neigh]){
	            dfs(neigh,vis,st,adj);
	        }
	    }
	    st.push(start);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>vis(V,0);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    int n=st.size();
	    vector<int>ans;
	    for(int i=0;i<n;i++){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
