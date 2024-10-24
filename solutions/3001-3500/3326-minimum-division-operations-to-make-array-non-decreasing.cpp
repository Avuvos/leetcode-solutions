class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] <= nums[i + 1]) continue;
            vector<int> divs;
            for (int d = 2; d * d <= nums[i]; d++) {
                if (nums[i] % d == 0) {
                    divs.push_back(d);
                    if (nums[i] / d != d) {
                        divs.push_back(nums[i] / d);
                    }
                }
            }
            sort(divs.rbegin(), divs.rend());
            for (auto &d: divs) {
                if (nums[i] <= nums[i + 1]) break;
                nums[i] /= d;
                ans++;
            }
            if (nums[i] > nums[i + 1]) {
                return -1;
            }
        }
        return ans;
    }
};
