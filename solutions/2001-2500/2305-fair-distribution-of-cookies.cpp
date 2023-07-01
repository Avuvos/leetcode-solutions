class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> sums(8, 0);
        function<int(int)> dfs = [&](int index) {
            if (index >= cookies.size()) {
                return *max_element(sums.begin(), sums.end());
            }
            int ans = 1e9;
            for (int i = 0; i < k; i++) {
                sums[i] += cookies[index];
                ans = min(ans, dfs(index + 1));
                sums[i] -= cookies[index];
            }
            return ans;
        };
        return dfs(0);
    }
};
