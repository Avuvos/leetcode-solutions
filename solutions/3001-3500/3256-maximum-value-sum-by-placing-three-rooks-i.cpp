#pragma GCC optimize("O3","unroll-loops")
#pragma GCC optimize("Ofast")
class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = board.size(), m = board[0].size();    
        vector<array<pair<int, int>, 3>> best(n);
        for (int i = 0; i < n; i++) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            for (int j = 0; j < m; j++) {
                pq.push({board[i][j], j});
                if (pq.size() > 3) pq.pop();
            }
            assert(pq.size() >= 3);
            for (int iter = 0; iter < 3; iter++) {
                auto [val, idx] = pq.top();
                best[i][2 - iter] = {val, idx};
                pq.pop();
            }
        }
        
        long long ans = -1e18;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    vector<int> order = {i, j, k};
                    do {
                        int seen1 = -1, seen2 = -1;
                        long long value = 0;
                        for (auto &idx: order) {
                            int x = best[idx][0].second;
                            int y = best[idx][1].second;
                            if (x != seen1 && x != seen2) {
                                seen1 = (seen1 != -1 ? seen1 : x);
                                seen2 = (seen1 != -1 ? x : seen2);
                                value += best[idx][0].first;
                            } else if (y != seen1 && y != seen2) {
                                seen1 = (seen1 != -1 ? seen1 : y);
                                seen2 = (seen1 != -1 ? y : seen2);
                                value += best[idx][1].first;
                            } else {
                                seen1 = (seen1 != -1 ? seen1 : best[idx][2].second);
                                seen2 = (seen1 != -1 ? best[idx][2].second : seen2);
                                value += best[idx][2].first;
                            }
                        }
                        ans = max(ans, value);
                    } while (next_permutation(order.begin(), order.end()));
                }
            }
        }
        return ans;
    }
};
