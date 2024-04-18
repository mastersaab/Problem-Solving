vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int m=grid.size();
	    int n=grid[0].size();
	    vector<vector<int>>vis(m,vector<int>(n,0));
	    vector<vector<int>>distance(m,vector<int>(n,0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int row=0;row<m;row++){
	        for(int col=0;col<n;col++){
	            if(grid[row][col]==1){
	                q.push({{row,col},0});
	                vis[row][col]=1;
	            }
	            else{
	                vis[row][col]=0;
	            }
	        }
	    }
	    int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int nrow=q.front().first.first;
            int ncol=q.front().first.second;
            int nsteps=q.front().second;
            q.pop();
            distance[nrow][ncol]=nsteps;
            for(int i=0;i<4;i++){
              int newrow=nrow+delrow[i];
              int newcol=ncol+delcol[i];
              if(newrow>=0 && newrow<m && newcol>=0 && newcol<n  && !vis[newrow][newcol]){
                  vis[newrow][newcol]=1;
                  q.push({{newrow,newcol},nsteps+1});
              }
            }
         }
	    return distance;
	}
