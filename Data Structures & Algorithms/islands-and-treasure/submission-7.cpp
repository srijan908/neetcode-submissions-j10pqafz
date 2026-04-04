class Solution {
public:
    vector<vector<int>> moves = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    v.push_back({i, j});
                }
            }
        }
        for (vector<int> c : v) {
            queue<vector<int>> q;
            vector<vector<bool>> visited(n, vector<bool> (m));
            q.push(c);
            int level = 0;
            while(!q.empty()) {
                int height = q.size();
                while(height--) {
                    vector<int> cur = q.front();
                    q.pop();
                    int a = cur[0], b = cur[1];
                    for (vector<int> mv : moves) {
                        int i = a + mv[0], j = b + mv[1];
                        if (i >= 0 and j >= 0 and i < n and j < m and !visited[i][j] and grid[i][j] != -1 and grid[i][j] != 0) {
                            grid[i][j] = min(grid[i][j], level + 1);
                            visited[i][j] = true;
                            q.push({i, j});
                        }
                    }
                }
                level++;
            }
        }
    }
};
