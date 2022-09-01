class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size();
        int n = nums.size();
        vector<int> answer(m);
        sort(nums.begin(), nums.end());
        for (int index = 0; index < m; ++index) {
            int q = queries[index];
            int cnt = 0;
            long long sum = 0;
            for (int i = 0; i < n; ++i) {
                if (sum + nums[i] > q) break;
                sum += nums[i];
                cnt++;
            }
            answer[index] = cnt;
        }
        return answer;
    }
};
