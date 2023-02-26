class Solution {
public:
typedef long long ll;
const ll INF=1e6;
typedef pair<int, int> PII;
typedef priority_queue<pair<ll, PII>, vector<pair<ll, PII>>, greater<>> min_priority_queue_PII;
int n,m;
vector<vector<pair<int, int>>> wg;
vector<vector<ll>> dist;
vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void fast_dijkstra(vector<pair<int, int>>& sources, vector<vector<int>>& grid) {
    dist=vector<vector<ll>>(n, vector<ll>(m, INF));
    //use priority queue in which top element has the "smallest" priority (min-heap)
    min_priority_queue_PII Q;

    for (auto [x, y] :sources){
        Q.push(make_pair(0, make_pair(x, y))); dist[x][y] = 0;
    }
    while (!Q.empty()) {
        pair<ll, PII> p = Q.top(); Q.pop();
        int herex = p.second.first;
        int herey = p.second.second;
        if (dist[herex][herey] != p.first) continue;// we just left it in Q until now instead of delete when we updated dist[here].
        for (auto [dx, dy]: dirs) {
            int nx = dx + herex, ny = dy + herey;
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            ll cur_weight = INF;
            if (grid[nx][ny] <= dist[herex][herey] + 1) cur_weight = 1;
            else if (herex != 0 || herey != 0) {
                ll delta = grid[nx][ny] - dist[herex][herey];
                cur_weight = delta;
                if (delta % 2 == 0) cur_weight++;
                if (delta < 0) cur_weight = 1;
            }
            if (dist[herex][herey] + cur_weight < dist[nx][ny]) {
                dist[nx][ny] = dist[herex][herey] + cur_weight;
                Q.push(make_pair(dist[nx][ny], make_pair(nx, ny)));
            } //1 5
                       //we are at 1 we need to wait to 5
                       //so 1->2, 2->1 passed 2 seconds
            //can go 1->2, 2->1, 1->3, 3->4, 4->5?
                       //1->2, 2->1 passed 4, now 1->2, 2->1 is 6 seconds
        }
    }
    }
    
    int minimumTime(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        vector<pair<int, int>> sources = {{0, 0}};
        fast_dijkstra(sources, grid);
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < m; j++) {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dist[n - 1][m - 1];
    }
};
