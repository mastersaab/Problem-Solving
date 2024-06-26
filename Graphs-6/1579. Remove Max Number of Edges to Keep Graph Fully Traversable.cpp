bool static compare(vector<int>& a,vector<int>& b){
        return a[0] > b[0];
    }
    vector<int> par1, par2, rank1, rank2;
    int remove=0;
    int count1=1;
    int count2=1;
    int find1(int &x){
        
        if(par1[x]==x) return x;
        
        else return par1[x] = find1(par1[x]);
    }
    
    bool union1(int &_x, int &_y){
        int x = find1(_x);
        int y = find1(_y);

        if(x!=y){
            if(rank1[y]>rank1[x]) par1[x] = y;
            
            else if(rank1[x]>rank1[y]) par1[y] = x;
            
            else{
                par1[x] = y;
                rank1[y]++;
            }
            return true;
        }
        return false;
    }
    
    int find2(int &x){
        
        if(par2[x]==x) return x;
        else return par2[x] = find2(par2[x]);
    }
    
    bool union2(int &_x, int &_y){
        
        int x = find2(_x);
        int y = find2(_y);
        
        if(x!=y){
            
            if(rank2[y]>rank2[x]) par2[x] = y;
            
            else if(rank2[x]>rank2[y]) par2[y] = x;
            else{
                par2[x] = y;
                rank2[y]++;
            }
            return true;
        }
        return false;
    }
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(), edges.end(), compare);
        par1.resize(n+1);
        par2.resize(n+1);
        rank1.resize(n+1,0);
        rank2.resize(n+1,0);
        
        for(int i=0;i<=n;++i){
            par1[i]=i;
            par2[i]=i;
        }
        
        for(auto &edge: edges){
            if(edge[0]==3){
                
                if(union1(edge[1],edge[2])  && union2(edge[1],edge[2])){
                    count1++;   
                    count2++;
                }
                else{
                    remove++;
                }   
            }
            else if(edge[0]==2){
                if(union2(edge[1],edge[2])) count2++;
                else remove++;
            }
            else{
                if(union1(edge[1],edge[2])) count1++;
                else remove++;
            }
        }
        if(count1 !=n || count2!=n) return -1;
        return remove; 
    }
