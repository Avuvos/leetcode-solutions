class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        long long ans = 0;
        for (auto &x: nums) {
            int cand = x;
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    if (st.contains(d)) {
                        cand = min(cand, d);
                    }
                    if (st.contains(x / d)) {
                        cand = min(cand, x / d);
                    }
                }
            }
            ans += cand;
        }
        return ans;
    }
};
