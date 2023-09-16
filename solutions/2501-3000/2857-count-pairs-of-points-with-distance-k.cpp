class Solution {
public:
    int countPairs(vector<vector<int>>& cor, int k) {
        int n = (int) cor.size();
        map<pair<int, int>, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = cor[i][0], y = cor[i][1];
            for (int p = 0; p <= k; p++) {
                int tx = p ^ x;
                int ty = (k - p) ^ y;
                ans += mp[make_pair(tx, ty)];
            }
            mp[make_pair(x, y)]++;
        }
        return ans;
    }
};
