string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>>vis(A+1,vector<int>(B+1,0));
    for(int x=0;x<=A;x++){
        for(int y=0;y<=B;y++){
            // FOR CHECKING THAT EVERY POINT IS INSIDE A CIRCLE OR NOT
            for(int k=0;k<E.size();k++){
                // HAR EK POINT X AUR Y ARRAY SE UTHAO AUR COMPARE KRO USSE 
                // FOR COMPARE :-> (x-x')^2 +(y-y')^2 <= d^2
                if((E[k]-x)*(E[k]-x)+(F[k]-y)*(F[k]-y)<=D*D){
                    vis[x][y]=1;
                    // break;
                }
            }
        }
    }
    if(vis[0][0]==1) return "NO";
    // CALL BFS FOR EACH COORDINATE
    queue<pair<int,int>>q;
    q.push({0,0});
    vis[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        // REACHED
        if(x==A && y==B) return "YES"; 
        // CHECK 8 DIRECTIONS
        for(int i=-1;i<=1;i++){
            for(int j=-1;j<=1;j++){
                int newx=x+i;
                int newy=y+j;
                // NOT OUT OF BOUND AND NOT VISITED
                if(newx>=0 && newx<=A && newy>=0 && newy<=B && !vis[newx][newy]){
                    vis[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
    }
    return "NO";
}
