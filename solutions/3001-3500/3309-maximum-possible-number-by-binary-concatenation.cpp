class Solution {
public:
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int best = 0;
        do {
            string ans;
            for (auto x: nums) {
                while (x > 0) {
                    ans += to_string(x % 2);
                    x /= 2;
                }
            }
            int res = 0;
            for (int bit = 0; bit < ans.size(); bit++) {
                if (ans[bit] == '1') {
                    res |= (1 << bit);
                }
            }
            best = max(best, res);
        } while (next_permutation(nums.begin(), nums.end()));
        return best;
    }
};
