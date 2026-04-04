class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(m, vector<bool> (n));
        vector<vector<int>> moves = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' and !vis[i][j]) {
                    ans++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = true;
                    while (!q.empty()) {
                        int a = q.front().first, b = q.front().second;
                        q.pop();
                        for (auto u : moves) {
                            int x = a + u[0], y = b + u[1];
                            if (x >=0 and x < m and y >= 0 and y < n and grid[x][y] == '1' and !vis[x][y]) {
                                vis[x][y] = true;
                                q.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};
