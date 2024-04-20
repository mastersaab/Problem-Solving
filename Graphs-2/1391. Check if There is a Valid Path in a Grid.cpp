class Solution {
public:
    bool isValid(int nx, int ny, int a, int b, vector<vector<int>>& grid) {
        if (a == 0 && b == 1) {
            if (grid[nx][ny] == 1 || grid[nx][ny] == 3 || grid[nx][ny] == 5)
                return true;
        }
        if (a == 0 && b == -1) {
            if (grid[nx][ny] == 6 || grid[nx][ny] == 4 || grid[nx][ny] == 1)
                return true;
        }
        if (a == 1 && b == 0) {
            if (grid[nx][ny] == 2 || grid[nx][ny] == 5 || grid[nx][ny] == 6)
                return true;
        }
        if (a == -1 && b == 0) {
            if (grid[nx][ny] == 3 || grid[nx][ny] == 4 || grid[nx][ny] == 2)
                return true;
        }  
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

        q.push({0, 0});
        vis[0][0] = 1;

        vector<vector<int>> dp[6] = {{{0, -1}, {0, 1}}, {{-1, 0}, {1, 0}}, {{0, -1}, {1, 0}}, {{0, 1}, {1, 0}}, {{0, -1}, {-1, 0}}, {{-1, 0}, {0, 1}}};

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if (x == n - 1 && y == m - 1)
                return true;
            
            for (int i = 0; i < 6; i++) {
                if (grid[x][y] == i + 1) {
                    for (auto it : dp[i]) {
                        int nx = x + it[0];
                        int ny = y + it[1];

                        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny]) {
                            if (isValid(nx, ny, it[0], it[1], grid)) {
                                q.push({nx, ny});
                                vis[nx][ny] = 1;
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};
