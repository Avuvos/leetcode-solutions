class Solution {
public:
    const int MOD = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(), ranges.end());
        int comps = 1;
        int right = ranges[0][1];
        for (int i = 1; i < ranges.size(); ++i) {
            if (ranges[i][0] <= right) {
                right = max(right, ranges[i][1]);
            } else {
                right = ranges[i][1];
                comps *= 2;
                comps %= MOD;
            }
        }
        return (comps * 2) % MOD;
    }
};
