class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> ps(1e6 + 2, 0);
        for (auto &i: intervals) {
            ps[i[0]]++;
            ps[i[1] + 1]--;
        }
        int ans = 1;
        for (int i = 1; i <= 1e6; i++) {
            ps[i] += ps[i - 1];
            ans = max(ans, ps[i]);
        }
        return ans;
    }
};
