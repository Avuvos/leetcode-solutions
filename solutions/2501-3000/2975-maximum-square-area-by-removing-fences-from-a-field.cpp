class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        unordered_set<int> cands;
        h.push_back(1);
        h.push_back(m);
        for (int i = 0; i < h.size(); i++) {
            for (int j = i + 1; j < h.size(); j++) {
                cands.insert(abs(h[i] - h[j]));
            }
        }
        v.push_back(1);
        v.push_back(n);
        long long ans = -1;
        const int MOD = 1e9 + 7;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                int d = abs(v[i] - v[j]);
                if (cands.find(d) != cands.end()) {
                    ans = max(ans, 1LL * d * d);
                }
            }
        }
        return ans % MOD;
    }
};
