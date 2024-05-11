class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        int n = (int) word.size();
        unordered_map<string, int> cnt;
        int mx = 0;
        for (int i = 0; i < n; i += k) {
            mx = max(mx, ++cnt[word.substr(i, k)]);
        }
        return (n + k - 1) / k - mx;
    }
};
