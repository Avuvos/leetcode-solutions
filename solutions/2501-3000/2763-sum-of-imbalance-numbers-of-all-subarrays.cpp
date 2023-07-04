class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = (int) nums.size(), ans = 0;
        for (int l = 0; l < n; l++) {
            int current = 0;
            multiset<int> s;
            for (int r = l; r < n; r++) {
                s.insert(nums[r]);
                auto it = s.find(nums[r]);
                if (it != s.begin() && next(it) != s.end() && (*next(it) - *prev(it) > 1)) {
                    current--;
                }
                if (it != s.begin() && nums[r] - *prev(it) > 1) {
                    current++;
                }
                if (next(it) != s.end() && *next(it) - nums[r] > 1) {
                    current++;
                }
                ans += current;
            }
        }
        return ans;
    }
};
