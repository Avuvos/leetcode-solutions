class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = (int) nums.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int i, const int j) {
           return nums[i] < nums[j]; 
        });
        vector<vector<int>> groups;
        for (int i = 0; i < n; i++) {
            int idx = order[i];
            if (i == 0 || nums[idx] - nums[groups.back().back()] > limit) {
                groups.push_back({});
            }
            groups.back().push_back(idx);
        }
        
        vector<int> ans(n);
        for (auto group: groups) {
            sort(group.begin(), group.end(), [&](const int i, const int j) {
                return nums[i] < nums[j];
            });
            auto indices = group;
            sort(indices.begin(), indices.end());
            for (int i = 0; i < group.size(); i++) {
                ans[indices[i]] = nums[group[i]];
            }
        }
        return ans;
    }
};
