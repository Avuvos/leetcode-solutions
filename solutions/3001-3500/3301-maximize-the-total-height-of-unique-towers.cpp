class Solution {
public:
    long long maximumTotalSum(vector<int>& a) {
        long long ans = 0;
        sort(a.rbegin(), a.rend());
        long long prev = 1e9+2;
        for (auto &h: a) {
            while (h >= prev && h >= 1) {
                h--;
            }
            if (h <= 0) {
                return -1;
            }
            ans += h;
            prev = h;
        }
        return ans;
    }
};
