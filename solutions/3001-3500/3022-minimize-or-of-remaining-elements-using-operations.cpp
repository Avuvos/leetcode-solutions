class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        int ans = 0, mask = 0;
        for (int bit = 29; bit >= 0; bit--) {        
            mask |= (1 << bit);
            int cnt = 0;
            int curAnd = mask;
            for (auto &x: nums) {
                curAnd &= x;
                if ((curAnd | ans) != ans) {
                    cnt++;
                } else {
                    curAnd = mask;
                }
            }
            if (cnt > k) {
                ans |= (1 << bit);
            }
        }
        return ans;
    }
};
