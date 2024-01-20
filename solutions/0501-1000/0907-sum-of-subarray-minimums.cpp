class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = (int) arr.size();
        const int MOD = 1e9 + 7;
        vector<int> sl(n, -1), sr(n, n);
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && arr[i] <= arr[stk.back()]) {
                sr[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        stk.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && arr[i] < arr[stk.back()]) {
                sl[stk.back()] = i;
                stk.pop_back();
            }
            stk.push_back(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = sl[i], r = sr[i];
            ans += 1LL * (r - i) * (i - l) * arr[i];
            ans %= MOD;
        }
        return ans;
    }
};
