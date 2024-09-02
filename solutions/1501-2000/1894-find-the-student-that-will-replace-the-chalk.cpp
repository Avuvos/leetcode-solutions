class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(), chalk.end(), 0LL);
        k %= sum;
        for (int i = 0; i < n; i++) {
            if (chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};
