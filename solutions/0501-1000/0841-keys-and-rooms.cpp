class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> g;
    void dfs(int u) {
        visited[u] = true;
        for (auto v: g[u]) {
            if (!visited[v]) {
                dfs(v);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        g = rooms;
        visited = vector<bool>(n, false);
        dfs(0);
        for (int r = 0; r < n; r++) {
            if (!visited[r]) return false;
        }
        return true;
        
    }
};
