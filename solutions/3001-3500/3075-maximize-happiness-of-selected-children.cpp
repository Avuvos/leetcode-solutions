class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans = 0;
        int delta = 0;
        for (int i = 0; i < k; i++) {
            happiness[i] -= delta;
            delta += 1;
            if (happiness[i] > 0) {
                ans += happiness[i];
            }
        }
        return ans;
    }
};
