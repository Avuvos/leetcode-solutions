class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());
        vector<pair<int, int>> merged;
        for (auto &i: occupiedIntervals) {
            int l = i[0], r = i[1];
            if (merged.size() == 0 || l > merged.back().second + 1) {
                merged.push_back({l, r});
            } else {
                merged.back().second = max(merged.back().second, r);
            }
        }
        vector<vector<int>> ans;
        for (auto &m :merged) {
            int l = m.first, r = m.second;
            if (l > freeEnd || r < freeStart) {
                ans.push_back({l, r});
                continue;
            }
            if (l >= freeStart && r <= freeEnd) {
                continue;
            }
            if (l < freeStart && r > freeEnd) {
                ans.push_back({l, freeStart - 1});
                ans.push_back({freeEnd + 1, r});
                continue;
            }
            if (l <= freeStart && r >= freeStart && r <= freeEnd) {
                l = min(l, freeStart - 1);
                r = freeStart - 1;
            }
            else {
                r = max(r, freeEnd + 1);
                l = freeEnd + 1;
            }
            ans.push_back({l, r});
        }
        return ans;
    }
};
