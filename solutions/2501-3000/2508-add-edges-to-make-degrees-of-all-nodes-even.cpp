class Solution {
public:
    vector<unordered_set<int>> g;
    bool not_connected(int a, int b) {
        return g[a].find(b) == g[a].end();
    }
    
    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n + 1, 0);
        g = vector<unordered_set<int>>(n + 1);
        for (auto& e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        
        vector<int> odd_degs;
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2 == 1) odd_degs.push_back(i);
        }
        int sz = odd_degs.size();
        if (sz > 4 || sz == 1 || sz == 3) return false;
        if (sz == 0) return true;
        
        if (sz == 2) {
            for (int i = 1; i <= n; i++) {
                if (i == odd_degs[0] || i == odd_degs[1]) continue;
                if (not_connected(odd_degs[0], i) && not_connected(odd_degs[1], i)) return true;
            }
            return g[odd_degs[0]].find(odd_degs[1]) == g[odd_degs[0]].end();
        }
        
        //(1, 2), (3, 4)
        //(1, 3), (2, 4)
        //(1, 4), (2, 3)
        
        int n1 = odd_degs[0], n2 = odd_degs[1], n3 = odd_degs[2], n4 = odd_degs[3];
        if (not_connected(n1, n2) && not_connected(n3, n4)) return true;
        if (not_connected(n1, n3) && not_connected(n2, n4)) return true;
        if (not_connected(n1, n4) && not_connected(n2, n3)) return true;
        return false;
        
        
        
    }
};
