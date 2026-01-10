class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;
        while (true) {
            int n = nums.size();
            if (is_sorted(nums.begin(), nums.end())) {
                break;
            }
            int mins = 1e5, idx = -1;
            for (int i = 0; i + 1 < n; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < mins) {
                    mins = s;
                    idx = i;
                }
            }
            vector<int> next_nums;
            for (int i = 0; i < n; i++) {
                if (i == idx + 1) continue;
                int val = nums[i];
                if (i == idx) {
                    val = mins;
                }
                next_nums.push_back(val);
            }
            swap(nums, next_nums);
            ops++;
        }
        return ops;
    }
};
