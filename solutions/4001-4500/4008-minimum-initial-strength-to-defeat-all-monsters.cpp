class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int n = monsters.size();
        vector<long long> bonus(n + 1, 0);
        for (auto &b: boosts) {
            int l = b[0], r = b[1], v = b[2];
            bonus[l] += v;
            bonus[r + 1] -= v;
        }
        for (int i = 0; i < n; i++) {
            bonus[i + 1] += bonus[i];
        }

        auto ok = [&](long long str) -> bool {
            for (int i = 0; i < n; i++) {
                if (str + bonus[i] < monsters[i]) {
                    return false;
                }
                str = max(str - monsters[i], 0LL);
            }
            return true;
        };


        long long left = 0, right = 1e15, ans = -1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (ok(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
