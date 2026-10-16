class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<int> ans;
        for (int i = 2; i <= n; i++) {
            int x = i;
            bool prime = true;
            for (int d = 2; d * d <= i; d++) {
                if (i % d == 0) {
                    prime = false;
                    break;
                }
            }
            if (prime) {
                if (s - i >= 0) {
                    s -= i;
                    ans.push_back(i);
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};
