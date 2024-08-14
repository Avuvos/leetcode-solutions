class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int, int> counts;
        for (auto &c: candidates) {
            counts[c] += 1;
        }
        vector<pair<int, int>> pairs;
        for (auto [key, val]: counts) {
            pairs.emplace_back(key, val);
        }
        int n = (int) pairs.size();
        vector<vector<int>> ans;
        auto dfs = [&](auto &dfs, int index, int sum, vector<int>& cur) -> void {
            if (sum == target) {
                ans.push_back(cur);
                return;
            }
            if (index >= n) {
                return;
            }
            dfs(dfs, index + 1, sum, cur);
            auto [val, cnt] = pairs[index];
            for (int i = 1; i <= cnt; i++) {
                int next_sum = sum + val * i;
                if (next_sum > target) break;
                cur.push_back(val);
                dfs(dfs, index + 1, next_sum, cur);
            }
            while (!cur.empty() && cur.back() == val) {
                cur.pop_back();
            }
        };
        
        vector<int> cur;
        dfs(dfs, 0, 0, {cur});
        return ans;
    }
};
