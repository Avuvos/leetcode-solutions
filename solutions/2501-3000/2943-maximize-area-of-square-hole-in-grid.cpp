class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        long long ans = 1;
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        auto calc = [&](vector<int>& a) {
            int cur = 1;
            int ans = 1;
            for (int i = 0; i + 1 < a.size(); i++) {
                if (a[i] + 1 == a[i + 1]) {
                    cur++;
                } else {
                    cur = 1;
                }
                ans = max(ans, cur);
            }
            return ans;
        };
        int d = 1 + min(calc(v), calc(h));
        return 1LL * d * d;
    }
};
