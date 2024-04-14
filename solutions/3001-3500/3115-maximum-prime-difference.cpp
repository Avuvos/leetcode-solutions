class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        
        auto pr = [&](int x) -> bool {
            if (x == 1) return false;
            for (int i = 2; i * i <= x; i++) {
                if (x % i == 0) return false;
            }
            return true;
        };
        
        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (pr(nums[i])) {
                l = i;
                break;
            }
        }
        int r = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (pr(nums[i])) {
                r = i;
                break;
            }
        }
        return r - l;
    }
};
