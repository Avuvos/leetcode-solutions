class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = (int) points.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int i, const int j) {
            return max(abs(points[i][0]), abs(points[i][1])) < max(abs(points[j][0]), abs(points[j][1]));
        });
        
        
        auto can = [&](int cnt) -> bool {
            set<char> seen;
            int radius = 0;
            for (int j = 0; j < cnt; j++) {
                int i = order[j];
                if (seen.find(s[i]) != seen.end()) {
                    return false;
                }
                seen.insert(s[i]);
                radius = max(radius, max(abs(points[i][0]), abs(points[i][1])));
            }
            for (int j = cnt; j < n; j++) {
                int i = order[j];
                if (radius < max(abs(points[i][0]), abs(points[i][1]))) break;
                if (seen.find(s[i]) != seen.end()) {
                    return false;
                }
                seen.insert(s[i]);
            } 
            return true;
        };
        
        
        int left = 0, right = n;
        int ans = 0;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (can(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
