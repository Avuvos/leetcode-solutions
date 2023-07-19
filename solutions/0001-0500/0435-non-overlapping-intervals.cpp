class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int rightBound = -1e9, ans = 0;
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (l < rightBound) {
                ans++;
                rightBound = min(rightBound, r);
            } else {
                rightBound = max(rightBound, r);
            }
        }
        return ans;
    }
};
