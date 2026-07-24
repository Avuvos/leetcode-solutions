class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        long long s = 0;

        auto is_peak = [&](int i) -> bool {
            if (i > 0 && i < n - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return true;
            }
            if (i == 0 && nums[i] > nums[i + 1]) {
                return true;
            }
            if (i == n - 1 && nums[i] > nums[i - 1]) {
                return true;
            }
            return false;

        };

        for (int i = 0; i < n; i++) {
            if (is_peak(i)) {
                continue;
            }
            if (i < n - 1 && nums[i] < nums[i + 1]) {
                s += nums[i];
            }
            else {
                s -= nums[i];
            }
        }
        return s == 0 ? -1 : s > 0 ? 0 : 1; 
    }
};
