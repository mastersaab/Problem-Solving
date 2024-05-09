class Solution {
public:
class DSU{
    public:
    vector<int>size;
    vector<int>parent;
    vector<int>rank;
    DSU(int n){
        rank.resize(n+1);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
            rank[i]=0;
        }
    }
    int findparent(int node){
            // base case jab node hi uska parent ho
        if(node==parent[node]) return node;
            // log function to find the parent
        // return findparent(parent[node]);
            // for breaking the old path and directly connecting to new path of ultimate parent;
        return parent[node] = findparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int ulofu=findparent(u);
        int ulofv=findparent(v);
        if(ulofu==ulofv) return;
        if(size[ulofu]<size[ulofv]){
            parent[ulofu]=ulofv;
            size[ulofv]++;
        } 
        else if(size[ulofu]>=size[ulofv]){
            // or simple else also work here
            parent[ulofv]=ulofu;
            size[ulofu]++;
        }
    }
};
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n=edges.size();
       vector<vector<int>>ans;
       DSU dsu(n);
       for(auto edge:edges){
        if(dsu.findparent(edge[0])==dsu.findparent(edge[1])){
            ans.push_back(edge);
        }
        dsu.unionbysize(edge[0],edge[1]);
       }
       return ans.back();
    }
};
