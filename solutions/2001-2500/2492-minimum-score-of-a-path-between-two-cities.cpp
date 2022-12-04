typedef long long ll;
typedef priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_priority_queue;
vector<vector<pair<int, int>>> adj;

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
    adj = vector<vector<pair<int, int>>>(n + 1);
    for (auto e: roads) {
        adj[e[0]].push_back(make_pair(e[1], e[2]));
        adj[e[1]].push_back(make_pair(e[0], e[2]));
    }
    queue<int> q;
    q.push(1);
    int res = INT_MAX;
    vector<bool> visited = vector<bool>(n + 1, false);
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (visited[node]) continue;
        visited[node] = true;
        for (auto neib: adj[node]) {
            if (visited[neib.first]) continue;
            res = min(res, neib.second);
            q.push(neib.first);
        }
    }
    return res;
}
};
