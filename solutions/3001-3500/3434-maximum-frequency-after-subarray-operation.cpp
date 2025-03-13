class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> d(n);
        set<int> cands;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            d[i] = k - nums[i];
            cands.insert(d[i]);
            if (d[i] == 0) ans++;
        }
        if (ans == n) return ans;
        int k_count = count(nums.begin(), nums.end(), k);
        
        for (auto &c: cands) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                if (nums[i] == k) {
                    arr.push_back(-1);
                } else if (nums[i] + c == k) {
                    arr.push_back(1);
                }
            }
            int m = arr.size(), sum = 0;
            for (int r = 0, l = 0; r < m; r++) {
                sum += arr[r];
                while (l <= r && sum < 0) {
                    sum -= arr[l];
                    l++;
                }
                ans = max(ans, sum + k_count);
            }
        }
        return ans;        
    }
};
