class Solution {
public:
    vector<int> lexicalOrder(int n) {
        auto dfs = [&](auto &dfs, int cur) -> vector<int> {
            if (cur > n) {
                return {};
            }
            vector<int> result = {cur};
            for (int d = 0; d <= 9; d++) {
                vector<int> cur_result = dfs(dfs, cur * 10 + d);
                for (auto &x: cur_result) {
                    result.push_back(x);
                }
            }
            return result;
        };
        
        vector<int> ans;
        for (int d = 1; d <= 9; d++) {
            auto cur = dfs(dfs, d);
            for (auto &x: cur) {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
