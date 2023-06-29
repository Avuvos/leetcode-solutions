class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int sx = 0, sy = 0;
        const int inf = 1e9;
        vector<char> keys;
        map<char, pair<int, int>> keys_positions;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '@') {
                    sx = i, sy = j;
                }
                if (islower(grid[i][j])) {
                    keys.push_back(grid[i][j]);
                    keys_positions[grid[i][j]] = make_pair(i, j);
                }
            }
        }
        vector<pair<int, int>> direcions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        auto bfs_to_targetkey = [&](int sx, int sy, char target, set<char>& open_locks) -> int {
            queue<pair<int, int>> q;
            q.push({sx, sy});
            vector<vector<bool>> seen(n, vector<bool>(m, false));
            seen[sx][sy] = true;
            int dist = 0;
            while (!q.empty()) {
                int sz = (int) q.size();
                for (int iter = 0; iter < sz; iter++) {
                    auto [x, y] = q.front(); q.pop();
                    if (grid[x][y] == target) {
                        return dist;
                    }
                    for (auto [dx, dy]: direcions) {
                        int nx = x + dx, ny = y + dy;
                        if (nx < 0 || ny < 0 || ny >= m || nx >= n || grid[nx][ny] == '#' || seen[nx][ny]) continue;
                        if (isupper(grid[nx][ny]) && open_locks.find(grid[nx][ny]) == open_locks.end()) continue;
                        seen[nx][ny] = true;
                        q.push(make_pair(nx, ny));
                    }
                }
                dist++;
            }
            return inf;
        };

        auto bfs = [&](vector<char>& keys)-> int {
            int dist = 0;
            set<char> open_locks;
            int startX = sx, startY = sy;
            for (int index = 0; index < keys.size(); index++) {
                char c = keys[index];
                int current_dist = bfs_to_targetkey(startX, startY, c, open_locks);
//                dbg(index, current_dist)
                if (current_dist >= inf) return inf;
                open_locks.insert(toupper(c));
//                dbg(open_locks)
                dist += current_dist;
                startX = keys_positions[c].first, startY = keys_positions[c].second;
            }
            return dist;
        };

        sort(keys.begin(), keys.end());

        int ans = inf;
//        dbg(keys)
//        dbg(keys_positions)
        do {
            int current = bfs(keys);
//            dbg(current)
            ans = min(ans, current);
        }while (next_permutation(keys.begin(), keys.end()));

        return (ans >= inf ? -1 : ans);
    }
};
