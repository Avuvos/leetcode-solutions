class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        function<void(int, vector<int>)> dfs = [&](int start, vector<int> current) {
            if (current.size() == k) {
                ans.push_back(current);
                return;
            }
            if (start > n){
                return;
            }
            if (k - current.size() > n - start + 1) {
                return;
            }
            for (int x = start; x <= n; x++) {
                current.push_back(x);
                dfs(x + 1, current);
                current.pop_back();
            }
        };
        dfs(1, vector<int>{});
        return ans;
    }
};
