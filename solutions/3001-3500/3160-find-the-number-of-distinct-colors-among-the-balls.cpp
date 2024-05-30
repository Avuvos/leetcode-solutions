class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> mp;
        int q = (int) queries.size();
        vector<int> ans(q);
        map<int, int> ball_to_col;
        int cnt = 0;
        for (int i = 0; i < q; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            if (ball_to_col.find(x) != ball_to_col.end() && --mp[ball_to_col[x]] == 0) {
                cnt--;
            }
            ball_to_col[x] = y;
            if (++mp[y] == 1) {
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};
