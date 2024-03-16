class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for (auto x: nums) {
            vector<int> digits;
            int mx = 0;
            while (x > 0) {
                digits.push_back(x % 10);
                mx = max(mx, x % 10);
                x /= 10;
            }
            int cur = 0, it = 0;
            while (it < digits.size()) {
                cur *= 10;
                cur += mx;
                it++;
            }
            ans += cur;
        }
        return ans;
    }
};
