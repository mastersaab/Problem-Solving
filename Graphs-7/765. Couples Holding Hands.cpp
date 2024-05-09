class Solution {
    int merges=0;
    int parent[31];
    int find(int v) {
        return parent[v]==v?v:parent[v]=find(parent[v]);
    }
    void merge(int a, int b) {
        a=find(a);
        b=find(b);
        if (a==b) return;
        parent[b]=a;
        merges++;
    }
public:
    int minSwapsCouples(vector<int>& row) {
        merges=0;
        int n = row.size();
        n/=2;
        for(int i=0;i<n;i++) {
            parent[i]=i;
        }
        for(int i=0;i<n;i++) {
            int a = row[i*2];
            int b = row[i*2+1];
            merge(a/2, b/2);
        }
        return merges;

    }
};
