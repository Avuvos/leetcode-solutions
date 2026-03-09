class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        
        auto LIS = [&](vector<int> &a) -> int {
            vector<int> d;
            for (auto &x: a) {
                auto it = lower_bound(d.begin(), d.end(), x);
                if (it != d.end()) *it = x;
                else d.push_back(x);
            }
            return d.size();
        };

        int ans = 0;
        for (int bit = 0; bit < 30; bit++) {
            vector<int> a;
            for (auto &x: nums) {
                if ((x >> bit) & 1) {
                    a.push_back(x);
                }
            }
            if (a.size() <= ans) continue;
            ans = max(ans, LIS(a));
        }

        return ans;
    }
};
