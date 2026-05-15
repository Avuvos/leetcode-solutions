class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> closest(n);
        closest[0] = 1;
        closest[n - 1] = n - 2;
        for (int i = 1; i < n - 1; i++) {
            closest[i] = abs(nums[i] - nums[i - 1]) <= abs(nums[i] - nums[i + 1]) ? i - 1 : i + 1;
        }

        vector<int> savings_left(n + 1, 0), savings_right(n + 1, 0);
        for (int i = 0; i < n; i++) {
            savings_left[i + 1] = savings_left[i];
            if (closest[i] == i + 1) {
                savings_left[i + 1] += abs(nums[i + 1] - nums[i]) - 1; 
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            savings_right[i] = savings_right[i + 1];
            if (closest[i] == i - 1) {
                savings_right[i] += abs(nums[i - 1] - nums[i]) - 1; 
            }
        }

        vector<int> ans;
        for (auto &q: queries) {
            int l = q[0], r = q[1];
            int d = abs(nums[r] - nums[l]);
            int res = d;
            if (l <= r) {
                res -= (savings_left[r] - savings_left[l]);
            } else {
                res -= (savings_right[r + 1] - savings_right[l + 1]);
            }
            ans.push_back(res);
        }
        return ans;

    }
};
