class Solution {
public:
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        vector<vector<int>> ans;
        int n = (int) s.size();
        int q = (int) queries.size();
        unordered_map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                mp[0] = {i, i};
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') continue;
            int cur = 0;
            for (int j = i; j < min(n, i + 32); j++) {
                cur <<= 1;
                if (s[j] == '1') cur++;
                if (mp.find(cur) != mp.end()) {
                    if (i < mp[cur].first) mp[cur] = {i, j};
                } else {
                    mp[cur] = {i, j};
                }
            }
            
        }
        
        for (int i = 0; i < q; i++) {
            int target = queries[i][0] ^ queries[i][1];
            if (mp.find(target) == mp.end()) ans.push_back({-1, -1});
            else ans.push_back({mp[target].first, mp[target].second});
        }
        return ans;
    }
};
