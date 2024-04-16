 vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int>s;
        for(auto i:edges){
            int v=i[1];
            s.insert(v);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(s.find(i)==s.end()) ans.push_back(i); 
        }
        return ans;
    }
