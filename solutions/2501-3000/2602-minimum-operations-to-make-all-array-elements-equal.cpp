class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        long long n = (int) nums.size(), m = (int) queries.size();
        vector<long long> ps(n + 1, 0);
        vector<long long> ans(m);
        for (int i = 0; i < n; i++) {
            ps[i + 1] = ps[i] + nums[i];
        }

        for (int i = 0; i < m; ++i) {
            long long cur = 0, q = queries[i];
            auto it = lower_bound(nums.begin(), nums.end(), q);
            if (it == nums.end()) {
                cur = n*q - ps[n];
                ans[i] = cur;
                continue;
            }
            if (it == nums.begin()) {
                cur = ps[n] - n*q;
                ans[i] = cur;
                continue;
            }
            int index = it - nums.begin();
            long long leftSum = (index)*q - ps[index];
            long long rightSum = (ps[n] - ps[index]) - (n - index)*(q);
            //cout << index << " " << leftSum << " " << rightSum << endl;
            cur = leftSum + rightSum;
            ans[i] = cur;
        }
        return ans;
    }
};
