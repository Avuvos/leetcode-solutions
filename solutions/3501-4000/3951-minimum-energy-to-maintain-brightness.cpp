class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> merged;
        for (auto &i: intervals) {
            int l = i[0], r = i[1];
            if (merged.empty() || l > merged.back().second) {
                merged.emplace_back(l, r);
            } else {
                merged.back().second = max(merged.back().second, r);
            }
        }
        long long ans = 0, bulbs = (brightness + 2) / 3;
        for (auto [l, r]: merged) {
            ans += 1LL * (r - l + 1) * bulbs;
        }
        return ans;
    }
};
