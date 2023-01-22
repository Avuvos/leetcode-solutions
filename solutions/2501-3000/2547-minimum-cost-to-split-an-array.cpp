

class Solution {
public:
    int n;
    vector<vector<long long>> imp;
    vector<vector<long long>> memo;
    long long dfs(int index, int last) {
        if (index >= n) {
            return imp[min(n - 1, last)][n - 1];
        }
        if (memo[last][index] != -1) {
            return memo[last][index];
        }
        long long op1 = dfs(index + 1, last);
        long long op2 = imp[last][index] + dfs(index + 1, index + 1);
        memo[last][index] = min(op1, op2);
        return memo[last][index];
    }
    
    int minCost(vector<int>& nums, int k) {
        n = nums.size();
        imp = vector<vector<long long>>(n, vector<long long>(n, k));
        memo = vector<vector<long long>>(n, vector<long long>(n, -1));
        vector<int> cnt = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            cnt.assign(n, 0);
            int val = 0;
            for (int j = i; j < n; j++) {
                if (cnt[nums[j]] == 0) val++;
                else if (cnt[nums[j]] == 1) val--;
                cnt[nums[j]]++;
                imp[i][j] += j - i + 1 - val;
            }
        }
        return dfs(0, 0);   
    }
};
