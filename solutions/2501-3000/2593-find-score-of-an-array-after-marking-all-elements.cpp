typedef priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> min_priority_queue;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        min_priority_queue pq;
        vector<bool> marked = vector<bool>(nums.size(), false);
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pq.push({nums[i], i});
        }
        while (!pq.empty()) {
            auto [val, index] = pq.top(); pq.pop();
            if (marked[index]) continue;
            marked[index] = true;
            ans += val;
            if (index + 1 < nums.size()) marked[index + 1] = true;
            if (index - 1 >= 0) marked[index - 1] = true;
        }
        return ans;
    }
};
