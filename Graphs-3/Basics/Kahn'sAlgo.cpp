vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int>indegree(V,0);
	   for(int i=0;i<V;i++){
	       for(auto node:adj[i]){
	           indegree[node]++;
	       }
	   }
	   queue<int>q;
	   for(int i=0;i<V;i++){
	       if(indegree[i]==0){
	           q.push(i);
	       }
	   }
	   vector<int>ans;
	   while(!q.empty()){
	       int node=q.front();
	       q.pop();
	       ans.push_back(node);
	       for(auto neigh:adj[node]){
	           indegree[neigh]--;
	           if(indegree[neigh]==0){
	               q.push(neigh);
	           }
	       }
	   }
	   return ans;
	}
