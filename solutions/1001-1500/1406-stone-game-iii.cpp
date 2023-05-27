class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = (int) stoneValue.size();
        int s = 0;
        for (auto &v: stoneValue) s += v;
        
        int memo[50001][2];
        memset(memo, -1, sizeof(memo));
        function<int(int, int)> dfs = [&](int index, int alice) {
            if (index >= n) return 0;
            if (memo[index][alice] != -1) return memo[index][alice];
            int res = alice ? -1e9 : 1e9, sum = 0;
            for (int j = index; j < min(index + 3, n); j++) {
                sum += stoneValue[j];
                int cur = dfs(j + 1, 1 - alice);
                if (alice) {
                    cur += sum;
                    res = max(res, cur);
                } else {
                    res = min(res, cur);
                }
            }
            memo[index][alice] = res;
            return res;
        };
        int alice_score = dfs(0, 1);
        int bob_score = s - alice_score;
        if (alice_score > bob_score) {
            return "Alice";
        } else if (alice_score < bob_score) {
            return "Bob";
        }
        return "Tie";
    }
};
