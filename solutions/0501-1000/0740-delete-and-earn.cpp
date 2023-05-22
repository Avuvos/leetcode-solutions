class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> cnt;
        for (auto &a: nums) cnt[a]++;
        vector<int> A;
        for (auto [key, val]: cnt) {
            A.push_back(key);
        }
        vector<int> dp(A.size() + 1, -1);
        function<int(int)> dfs = [&](int index) {
            if (index >= A.size()) return 0;
            if (dp[index] != -1) return dp[index];
            int nxt_index = ((index + 1 < A.size() && A[index + 1] - A[index] > 1) ? index + 1 : index + 2);
            dp[index] = max(dfs(index + 1), A[index] *cnt[A[index]] + dfs(nxt_index));
            return dp[index];
        };
        return dfs(0);
    }
};
