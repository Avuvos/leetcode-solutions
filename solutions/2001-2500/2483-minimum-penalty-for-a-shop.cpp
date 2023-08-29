class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> suffix(n + 1, 0), prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (customers[i] == 'N');
        }
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + (customers[i] == 'Y');
        }
        int min_penalty = n, ans = 0;
        int closed = 0;
        for (int i = 0; i <= n; i++) {
            int penalty = prefix[i] + suffix[i];
            if (penalty < min_penalty) {
                min_penalty = penalty;
                ans = i;
            }
        }
        return ans;
    }
};
