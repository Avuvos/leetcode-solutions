class Solution {
public:
    typedef long long ll;
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = (int) parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        map<ll, ll> mp;
        ll ans = 0;
        function<void(int, int, ll)> dfs = [&](int u, int p, ll mask) {
            //calc xor from root to node
            mask ^= (1 << (s[u] - 'a'));
            
            //update the answer if we have seen that mask before
            ans += mp[mask];
            
            //allow masks to be the same up to one bit, which we put in the middle
            for (int i = 0; i < 26; i++) {
                ans += mp[mask ^ (1 << i)];
            }
            
            //update the map
            mp[mask]++;
            
            //run dfs on the children
            for (auto &v: g[u]) {
                if (v == p) continue;
                dfs(v, u, mask);
            }
        };
        dfs(0, -1, 0);
        return ans;
    }
};
