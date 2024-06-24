class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = (int) nums.size();
        vector<int> pref(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                pref[i] += pref[i - 1];
            }
            int f = pref[i] % 2;
            nums[i] ^= f;
            if (nums[i] == 0 && i < n - k + 1) {
                ans += 1;
                nums[i] = 1;
                pref[i] += 1;
                pref[i + k] -= 1;
            }
        }
        bool ok = all_of(nums.begin(), nums.end(), [&](int x){ return x == 1;}); 
        return ok ? ans : -1;
    }
};
