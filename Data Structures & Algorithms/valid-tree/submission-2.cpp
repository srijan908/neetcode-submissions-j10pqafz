class Solution {
public:
    vector<int> parent;
    void make_set(int n) {
        parent[n] = n;
    }
    int find_set(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = find_set(parent[n]);
    }
    void make_union(int a, int b) {
        int p1 = find_set(a), p2 = find_set(b);
        if (p1 != p2) {
            parent[p2] = p1;
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() < n - 1) {
            return false;
        }
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
        for (auto e : edges) {
            if (parent[e[0]] == parent[e[1]]) {
                return false;
            }
            make_union(e[0], e[1]);
        }
        return true;
    }
};
