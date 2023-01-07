class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diffs(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            diffs[i] = gas[i] - cost[i];
            sum += diffs[i];
        }
        if (sum < 0) return -1;
        
        int cur = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cur += diffs[i];
            if (cur < 0) {
                ans = i + 1;
                cur = 0;
            }
        }
        return ans;
    }
};
