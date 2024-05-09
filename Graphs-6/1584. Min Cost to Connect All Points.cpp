class DSU {
    vector<int> parent, size;

public:
    DSU(int n) {
        // Initialize the parent and size arrays for n+1 nodes
        parent.resize(n + 1);
        size.resize(n + 1);

        // Initialize each node as its own parent and size as 1
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        // Find the parent of a node using path compression
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool Union(int u, int v) {
        // Union two nodes if they are not in the same set
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return false;

        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = parent[ulp_v];
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = parent[ulp_u];
        }
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;  // {edgeweight, {node1, node2}}

        // Generate edges and calculate their weights
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({dist, {i, j}});  // i and j are current and next nodes respectively
            }
        }

        // Sort edges based on edge weight
        sort(edges.begin(), edges.end());

        DSU ds(n);  // Initialize Disjoint Set Union data structure

        int mncost = 0;     // Minimum cost of connecting points
        int edgesUsed = 0;  // Number of edges used

        // Kruskal's algorithm: Connect nodes to form the minimum spanning tree
        for (int i = 0; i < edges.size() and edgesUsed < n - 1; i++) {
            int edgeWeight = edges[i].first;
            int node1 = edges[i].second.first;
            int node2 = edges[i].second.second;

            if (ds.Union(node1, node2)) {
                mncost += edgeWeight;
                edgesUsed++;
            }
        }

        return mncost;
    }
};
