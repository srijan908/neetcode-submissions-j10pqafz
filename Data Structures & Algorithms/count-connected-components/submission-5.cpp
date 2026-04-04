class Solution {
public:
    vector<bool> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        visited.resize(n);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans++;
                dfs(i, adj);
            }
        }
        return ans;
    }
    void dfs(int node, vector<vector<int>>& adj) {
        if (visited[node]) {
            return;
        }
        visited[node] = true;
        for (auto cur : adj[node]) {
            dfs(cur, adj);
        }
    }
};
