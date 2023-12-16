class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        map<int, int> first;
        map<int, int> last;
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            last[nums[i]] = i;
        }
        for (int i = n - 1; i >= 0; i--) {
            first[nums[i]] = i;
        }
        vector<pair<int, int>> v;
        for (auto [key, val]: first) {
            v.push_back(make_pair(val, last[key]));
        }
        sort(v.begin(), v.end());
        int curR = 0;
        long long ans = 1;
        const int MOD = 1e9 + 7;
        for (auto [l, r]: v) {
            if (l > curR) {
                ans *= 2;
                ans %= MOD;
            }
            curR = max(r, curR);
        }
        return ans;
    }
};
