typedef long long ll;
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        ll even_sum = 0;
        for (auto a: nums) {
            if (a % 2 == 0) even_sum += a;
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int index = queries[i][1], val = queries[i][0];
            if (nums[index] % 2 == 0) even_sum -= nums[index];
            nums[index] = nums[index] + val;
            if (nums[index] % 2 == 0) even_sum += nums[index];
            ans[i] = even_sum;
        }
        return ans;
    }
};
