typedef long long ll;
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        ll res = 0, pairs = 0;
        unordered_map<int, int> cnt;
        int left = 0;
        int n = nums.size();
        for (int right = 0; right < n; right++) {
            int cur = nums[right];
            cnt[cur]++;
            ll x = cnt[cur];
            pairs += (x - 1);
            while (pairs >= k && left < right) {
                res += (n - right);
                // cout << left << " " << right << " " << pairs << endl;
                cnt[nums[left]]--;
                pairs -= cnt[nums[left]];
                left++;
                // cout << "pairs after down " << pairs << endl;
            }
        }
        return res;
    }
};
