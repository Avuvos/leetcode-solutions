class Solution {
public:

    bool is_bin_pal(int x) {
        string bx = bitset<14>(x).to_string();
        bx.erase(0, bx.find_first_not_of('0'));
        int l = 0, r = bx.size() - 1;
        while (l <= r) {
            if (bx[l] != bx[r]) return false;
            l++;
            r--;
        }
        return true;
    };

    vector<int> minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n), pals;
        for (int x = 1; x <= 5100; x += 2) { // Must be odd!
            if (is_bin_pal(x)) {
                pals.push_back(x);
            }
        }
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(pals.begin(), pals.end(), nums[i]);
            ans[i] = *it - nums[i];
            if (it != pals.begin()) {
                ans[i] = min(ans[i], nums[i] - *prev(it));
            }
        }
        return ans;
    }
};
