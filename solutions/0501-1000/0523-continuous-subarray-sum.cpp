class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> seen = {{0, 0}};
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = (sum + nums[i]) % k;
            auto it = seen.find(sum);
            if (it != seen.end() && it -> second < i) {
                return true;
            }
            if (it == seen.end()) {
                seen[sum] = i + 1;
            }
        }
        return false;
    }
};
