class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp; // num to freq
            map<int, int> freqs; // freq to count
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                freqs[mp[nums[j]]]++;
                if (mp[nums[j]] > 1 && --freqs[mp[nums[j]] - 1] == 0) {
                    freqs.erase(mp[nums[j]] - 1);
                }
                if (mp.size() == 1 || (freqs.size() == 2 && freqs.begin() -> first * 2 == freqs.rbegin() -> first)) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
}; 
