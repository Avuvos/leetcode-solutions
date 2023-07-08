class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        int n = (int) s.size();
        
        auto check = [&](int x) {
            if (x == 0) return false;
            while (x % 5 == 0) {
                x = x / 5;
            }
            return x == 1;
        };
        
        const int inf = 1e9;
        function<int(int, int)> dfs = [&](int index, int num) {
            if (index >= n) {
                return num == -1 ? 0 : inf;
            }
            int best = inf;
            if (num == -1) num = 0;
            num = num * 2 + s[index] - '0';
            if (index + 1 == n || s[index + 1] != '0') {
                if (check(num)) {
                    best = min(best, 1 + dfs(index + 1, -1));
                }
            }
            if (num > 0) {
                best = min(best, dfs(index + 1, num));
            }
            return best;
        };
        
        int ans = dfs(0, 0);
        return ans < inf ? ans : -1;
    }
};
