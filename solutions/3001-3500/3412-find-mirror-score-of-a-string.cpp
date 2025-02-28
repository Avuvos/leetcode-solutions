class Solution {
public:
    long long calculateScore(string s) {
        int n = s.size();
        vector<stack<int>> seen(26);
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int self = s[i] - 'a';
            int rev = 25 - self;
            if (seen[rev].empty()) {
                seen[self].push(i);
            } else {
                ans += i - seen[rev].top();
                seen[rev].pop();
            }
        }
        return ans;
    }
};
