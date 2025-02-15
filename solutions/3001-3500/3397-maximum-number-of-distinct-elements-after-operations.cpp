class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> s(n);
        int d = -k;
        s[0] = nums[0] + d;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                d++;
            } else {
                d = max(-k , s[i - 1] - nums[i] + 1);
            }
            d = min(d, k);
            s[i] = nums[i] + d;
        }

        set<int> res(s.begin(), s.end());
        return res.size();
    }
};
