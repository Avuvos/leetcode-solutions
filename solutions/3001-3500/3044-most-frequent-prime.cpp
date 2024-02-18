class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        map<int, int> mp;
        vector<pair<int, int>> directions = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0},
            {1, 1},
            {-1, -1},
            {1, -1},
            {-1, 1},
        };
        
        auto is_prime = [&](int x) {
            if (x <= 1) {
                return false;
            }
            for (int d = 2; d * d <= x; d++) {
                if (x % d == 0) {
                    return false;
                }
            }
            return true;
        };
        
        
        auto traverse = [&](int i, int j, int dx, int dy) {
            int num = 0;
            while (i >= 0 && i < n && j >= 0 && j < m) {
                num = num*10 + mat[i][j];
                if (is_prime(num)) {
                    mp[num]++;
                }
                i += dx;
                j += dy;
            }
        };
        
        auto go = [&](int i, int j) {
            for (auto [dx, dy]: directions) {
                traverse(i, j, dx, dy);
            }
        };
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                go(i, j);
            }
        }
        
        int maxFreq = 0, ans = -1;
        for (auto [key, val]: mp) {
            if (val >= maxFreq && key > 10) {
                maxFreq = val;
                ans = key;
            }
        }
        
        return ans;
        
    }
};
