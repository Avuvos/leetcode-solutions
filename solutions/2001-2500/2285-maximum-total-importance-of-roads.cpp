class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        for (auto &r: roads) {
            degree[r[0]]++;
            degree[r[1]]++;
        }
        sort(degree.begin(), degree.end());
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans += 1LL * (i + 1) * degree[i];
        }
        return ans;
    }
};
