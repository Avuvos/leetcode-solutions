class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        // (i, j, mask) = (min moves, max energy) to clear "mask"
        int n = classroom.size(), m = classroom[0].size(), l = 0;
        map<pair<int, int>, int> mp;
        int si = -1, sj = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (classroom[i][j] == 'S') {
                    si = i;
                    sj = j;
                }
                if (classroom[i][j] == 'L') {
                    mp[{i, j}] = l;
                    l++;
                }
            }
        }
        int L = (1 << l);
        const int inf = 1e9 + 2;
        vector<vector<vector<pair<int, int>>>> dp(n, vector<vector<pair<int, int>>>(m, vector<pair<int, int>>(L + 1, {inf, -1})));
        dp[si][sj][0] = {0, energy};
        priority_queue<tuple<int, int, int, int, int>> pq;
        pq.push({0, energy, si, sj, 0});
        while (!pq.empty()) {
            auto [d, e, i, j, mask] = pq.top(); pq.pop();
            // cout << d << " " << e << " " << i << " " << j << " " << mask << endl;
            d *= -1;
            if (__builtin_popcount(mask) == l) {
                return d;
            }
            if (dp[i][j][mask].first != d || dp[i][j][mask].second != e) continue;
            for (auto [dx, dy]: vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}) {
                int ni = i + dx;
                int nj = j + dy;
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (classroom[ni][nj] == 'X') continue;
                int ne = classroom[ni][nj] == 'R' ? energy : e - 1;
                if (ne < 0) continue;
                int nmask = mask;
                if (classroom[ni][nj] == 'L') {
                    nmask = nmask | (1 << mp[{ni, nj}]);
                }
                int nd = d + 1;
                if (ne > dp[ni][nj][nmask].second) {
                    if (ne == 0 && __builtin_popcount(nmask) < l) continue;
                    dp[ni][nj][nmask] = {nd, ne};
                    pq.push({-1 * nd, ne, ni, nj, nmask});
                }
            }
        }
        return -1;
        
    }
};
