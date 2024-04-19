int Solution::knight(int A, int B, int x, int y, int tx, int ty) {
    vector<vector<int>>vis(A,vector<int>(B,0));
    if(x==tx && y==ty) return 0;
    
    queue<pair<int,int>>q;
    q.push({x,y});
    vis[x][y]=1;
    
    int delrow[]={1,1,-1,-1,2,-2,2,-2};
    int delcol[]={2,-2,2,-2,1,1,-1,-1};
    int count=0;
    
    while(!q.empty()){
        count++;
        // The knight’s movements are being added to the queue in batches per step, so we should increment
        // count only when we have processed all movements for a particular step. we can achieve
        // this by keeping track of the size of the queue at the start of each iteration (which represents all the
        // movements for the current step), and then increment count when you have processed all of
        // these movements.
        int size=q.size();
        for(int i=0;i<size;i++){
        int nx=q.front().first;
        int ny=q.front().second;
        q.pop();
        for(int i=0;i<8;i++){
            int newx=nx+delrow[i];
            int newy=ny+delcol[i];
            if(newx==tx && newy==ty) return count;
            if(newx>=0 && newx<A && newy>=0 && newy<B && !vis[newx][newy]){
                vis[newx][newy]=1;
                q.push({newx,newy});
            }
        }
        }
        
    }
    return -1;
}
