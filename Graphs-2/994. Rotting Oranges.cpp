int freshorangesrotten=0;
    void bfs(queue<pair<pair<int,int>,int>>&q, vector<vector<int>>& vis,int& time,vector<vector<int>>& grid,int m,int n){
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            time=max(t,time);
            for(int i=0;i<4;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && vis[newrow][newcol]!=2 && grid[newrow][newcol]==1 ){
                 q.push({{newrow,newcol},t+1});
                 vis[newrow][newcol]=2;
                 freshorangesrotten++;
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int freshoranges=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q; //{{row,col},time}
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(grid[row][col]==2){
                    vis[row][col]=2;
                    q.push({{row,col},0});
                } 
                else vis[row][col]=0;
                if(grid[row][col]==1) freshoranges++;
            }
        }
        int time=0;
        bfs(q,vis,time,grid,m,n);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==1 && vis[i][j]!=2) return -1;
        //     }
        // }
        if(freshoranges!=freshorangesrotten) return -1;
        return time;
    }
