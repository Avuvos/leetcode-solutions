class Solution {
public:
    long long seen[2001][1001];
    long long dfs(int pos, int k, int endPos) {
        if (k == 0) {
            return pos == endPos;
        }
        int fixed_pos = pos;
        if (pos < 0) fixed_pos = abs(pos) + 1001;
        if (seen[fixed_pos][k] != -1) {
            return seen[fixed_pos][k];
        }

        seen[fixed_pos][k] = dfs(pos + 1, k - 1, endPos) + dfs(pos - 1, k - 1, endPos);
        return seen[fixed_pos][k] % (int)(pow(10, 9) + 7);
    }

    int numberOfWays(int startPos, int endPos, int k) {
        fill_n(&seen[0][0], 2001*1001, -1);
        return dfs(startPos, k, endPos);
    }
};
