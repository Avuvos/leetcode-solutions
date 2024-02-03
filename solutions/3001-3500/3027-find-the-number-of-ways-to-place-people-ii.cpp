class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = (int) points.size();
        sort(points.begin(), points.end(), [&](const vector<int> &v1, const vector<int> &v2) {
            return v1[0] == v2[0] ? v1[1] > v2[1] : v1[0] < v2[0];
        });
        
        set<int> seen;
        auto ok = [&](int i, int j) -> bool {
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];
            if (y2 > y1) return false;
            auto it = seen.lower_bound(y2);
            if (it == seen.end()) return true;
            if (*it <= y1) return false;
            return true;
        };
        
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            seen.clear();
            for (int j = i + 1; j < n; j++) {
                if (ok(i, j)) {
                    ans++;
                }
                seen.insert(points[j][1]);
            }
        }
        return ans;
    }
};
