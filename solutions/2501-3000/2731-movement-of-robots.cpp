class Solution {
public:
    typedef long  long ll;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = (int) nums.size();
        vector<pair<int, int>> both(n);
        ll MOD = 1e9 + 7;
        vector<ll> pos(n);
        for (int i = 0; i < n; i++) {
            int z = (s[i] == 'L' ? 0 : 1);
            both[i] = make_pair(nums[i], z);
        }
        sort(both.begin(), both.end());
        for (int i = 0; i < n; i++) {
            pos[i] = both[i].first;
        }

        for (int i = 0; i < n; i++) {
            if (both[i].second == 0) {
                pos[i] -= d;
            } else {
                pos[i] += d;
            }
        }
        
        sort(pos.begin(), pos.end());
        ll sum = pos[0], ans = 0;
        for (int i = 1; i < n; i++) {
            ans += (pos[i] * i - sum);
            sum += pos[i];
            ans %= MOD;
            sum %= MOD;
        }
        return ans;
    }
};
