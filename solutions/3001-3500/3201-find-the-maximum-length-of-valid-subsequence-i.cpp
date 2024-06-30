class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //either all even, all odd, or alternating
        int alt = 0, even = 0, odd = 0;
        int prev = -1;
        for (auto &x: nums) {
            if (x % 2 == 0) {
                even += 1;
            } else {
                odd += 1;
            }
            if (x % 2 != prev) {
                alt += 1;
                prev = x % 2;
            }
        }
        return max({alt, odd, even});
    }
};
