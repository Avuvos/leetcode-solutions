class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = (int) nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> a;
                for (int k = 0; k < n; k++) {
                    if (k < i || k > j) {
                        a.push_back(nums[k]);
                    }
                }
                if (is_sorted(a.begin(), a.end()) && unique(a.begin(), a.end()) == a.end()) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
