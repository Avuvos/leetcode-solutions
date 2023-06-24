class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = (int) words.size();
        
        string ab = "abcdefghijklmnopqrstuvwxyz";
        
        auto int_to_char = [&](int x) {
            return ab[x];
        };
        
        int dp[1001][26][26];
        memset(dp, -1, sizeof(dp));
        
        function<int(int, int, int)> dfs = [&](int index, int first, int last) {
            if (index >= n) {
                return 0;
            }
            if (dp[index][first][last] != -1) {
                return dp[index][first][last];
            }
            
            int delta = 0;
            if (words[index][0] - 'a' == last) {
                delta = -1;
            }
            int op1 = words[index].size() + delta + dfs(index + 1, first, words[index].back() - 'a');
            delta = 0;
            if (words[index].back() - 'a' == first) {
                delta = -1;
            }
            int op2 = words[index].size() + delta + dfs(index + 1, words[index][0] - 'a' , last);
            int ans = min(op1, op2);
            dp[index][first][last] = ans;
            return ans;
        };
        
        return words[0].size() + dfs(1, words[0][0] - 'a', words[0].back() - 'a');
        
    }
};
