class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        // observe that each room i contribues 0 to i points to the final answer.
        int n = damage.size();
        long long ans = 0;
        vector<long long> ps(n + 1);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + damage[i];
        }
        for (int i = 0; i < n; i++) {
            int l = 0, r = i, min_idx = i + 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (hp - requirement[i] >= ps[i + 1] - ps[m]) {
                    min_idx = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            ans += (i + 1 - min_idx);
        }
        return ans;

    }
};
