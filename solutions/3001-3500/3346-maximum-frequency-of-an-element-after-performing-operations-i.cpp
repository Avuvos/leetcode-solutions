class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1, 0), ps(mx + 2, 0);
        for (auto &x: nums) cnt[x]++;
        for (int i = 0; i <= mx; i++) {
            ps[i + 1] = ps[i] + cnt[i];
        }
        int best = 0;
        for (int i = 0; i <= mx; i++) {
            int l = max(0, i - k);
            int r = min(mx, i + k);
            int current = cnt[i];
            int total = ps[r + 1] - ps[l];
            best = max(best, current + min(total - current, numOperations));
        }
        return best;
    }
};
