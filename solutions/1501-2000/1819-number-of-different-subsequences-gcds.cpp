class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        const int N = 2e5 + 17;
        vector<int> a(N, 0);
        
        for (auto &x: nums) {
            for (int d = 1; d * d <= x; d++) {
                if (x % d == 0) {
                    a[d] = gcd(a[d], x);
                    a[x / d] = gcd(a[x / d], x);
                }
            }
        }
        
        int ans = 0;
        for (int x = 1; x < N; x++) {
            ans += (a[x] == x);
        }
        
        return ans;
    }
};
