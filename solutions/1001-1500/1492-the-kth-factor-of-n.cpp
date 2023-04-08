class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> f;
        for (int d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                f.push_back(d);
                if (d != n/d) f.push_back(n/d);
            }
        }
        sort(f.begin(), f.end());
        return f.size() >= k ? f[k - 1] : - 1;
    }
};
