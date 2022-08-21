class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        priority_queue<pair<int64_t, int64_t>> maxHeap;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long a = nums[i];
            if (a > 0) sum += a;
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end());
        maxHeap.push({sum - nums[0], 0});
        k--;
        for (int j = 0; j < k; j++) {
            auto [val, index] = maxHeap.top();
            maxHeap.pop();
            sum = val;
            if (index + 1 < nums.size()) {
                maxHeap.push({val + nums[index] - nums[index + 1] , index + 1});
                maxHeap.push({val - nums[index + 1] , index + 1});
            }
        }
        return sum;
    }
};
