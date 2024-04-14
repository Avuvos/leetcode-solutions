class Solution {
public:
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        int n = (int) nums.size();
        int m = (int) andValues.size();
        
        const int inf = 1e9 + 2;
        // map<tuple<int, int, int>, int> mp;
        vector<vector<unordered_map<int, int>>> mp(n, vector<unordered_map<int, int>> (m));
        auto dfs = [&](auto dfs, int i, int j, int mask) -> int {
            if (i >= n) {
                return j >= m ? 0 : inf;
            }
            if (j >= m) {
                return inf;
            }
            mask &= nums[i];
            if (mask < andValues[j]) {
                return inf;
            }
            // if (mp.find({i, j, mask}) != mp.end()) {
            //     return mp[{i, j, mask}];
            // }
            if (mp[i][j].find(mask) != mp[i][j].end()) {
                return mp[i][j][mask];
            }
            int take = inf, skip = inf;
            if (mask == andValues[j]) {
                take = nums[i] + dfs(dfs, i + 1, j + 1, (1 << 30) - 1);
            }
            skip = dfs(dfs, i + 1, j, mask);
            return mp[i][j][mask] = min(skip, take);
            
        };
        
        int ans = dfs(dfs, 0, 0, (1 << 30) - 1);
        return ans < inf ? ans : -1;
        
    }
};
