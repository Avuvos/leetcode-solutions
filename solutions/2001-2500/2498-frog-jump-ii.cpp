class Solution {
public:
    int maxJump(vector<int>& stones) {
        int res = stones[1];
        int n = stones.size();
        for (int i = 0; i < n - 2; i++) {
            res = max(res, stones[i + 2] - stones[i]);
        }
        return res;
    }
};
