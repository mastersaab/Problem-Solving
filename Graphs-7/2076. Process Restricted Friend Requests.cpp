class Solution {
public:
    vector<int>parent;
    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        parent.clear();
        parent.resize(n+1);
        vector<bool>ans;
        for(int i=0;i<n+1;i++)
        {
            parent[i]=i;
        }
        for(auto &it:requests)
        {
            int u=find(it[0]);
            int v=find(it[1]);
            bool success=true;
            for(auto &t:restrictions)
            {
                int u1=find(t[0]);
                int v1=find(t[1]);
                //direct and indirect relation (x<->y)
                if((u==u1&&v==v1)||(u==v1&&v==u1))
                {
                    success=false;
                    break;
                }
            }
            if(success)
            {
                ans.push_back(success);
                parent[u]=v;
            }
            else
            {
             ans.push_back(success);   
            }
        }
        return ans;
    }
};
