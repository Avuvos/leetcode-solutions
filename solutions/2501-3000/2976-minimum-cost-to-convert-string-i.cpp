class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = (int) source.size();
        long long ans = 0;
        const long long INF = 1e14;
        vector<vector<long long>> d(26, vector<long long>(26, INF));
        for (int i = 0; i < 26; i++) {
            d[i][i] = 0;
        }
        for (int i = 0; i < cost.size(); i++) {
            d[original[i] - 'a'][changed[i] - 'a'] = min(d[original[i] - 'a'][changed[i] - 'a'], (long long) cost[i]);
        }
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            ans += d[source[i] - 'a'][target[i] - 'a'];
        }
        return ans < INF ? ans : -1;
    }
};
