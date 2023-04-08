class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g = 0;
        for (auto &num: nums) g = gcd(g, num);
        return g == 1;
    }
};
