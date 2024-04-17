void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<char>>& board){
        vis[row][col]=1;
        int n=board.size();
        int m=board[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if((newrow>=0 && newrow<n) && (newcol>=0 && newcol<m) && (!vis[newrow][newcol] && board[newrow][newcol]=='O')){
                dfs(newrow,newcol,vis,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            //FIRST ROW
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,vis,board);
            }
            //LAST ROW
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1,i,vis,board);
            }
        }
        for(int i=0;i<n;i++){
            // FIRST COLUMN
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
            //LAST COLUMN
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }
        }
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && board[row][col]=='O') board[row][col]='X';
            }
        }
    }
