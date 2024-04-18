void bfs(int row,int col, vector<vector<int>>&vis,vector<vector<char>>& grid,int& count){
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n=grid.size();
        int m=grid[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int newrow=q.front().first;
            int newcol=q.front().second;
            q.pop();
            // CHECK IN 4 DIRECTIONS
            for(int i=0;i<4;i++){
                int nrow=newrow+delrow[i];
                int ncol=newcol+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]  ){
                    // count++;
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
            // CHECK IN 8 DIRECTIONS
            // for(int i=-1;i<=1;i++){
            //     for(int j=-1;j<=1;j++){
            //         int nrow=newrow+i;
            //         int ncol=newcol+j;
            //         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]  ){
            //             // count++;
            //             vis[nrow][ncol]=1;
            //             q.push({nrow,ncol});
            //         }
            //     }
            // }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    bfs(i,j,vis,grid,count);
                }
            }
        }
        return count;
    }
