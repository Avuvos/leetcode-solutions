class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        set<int> losers;
        vector<bool> seen(n, false);
        seen[0] = true;
        for (int i = 1; i < n; i++) {
            losers.insert(i);
        }
        long long p = 1;
        long long cur = 0;
        while (true) {
            cur = (cur + p * k) % n;
            p++;
            if (seen[cur]) break;
            seen[cur] = true;
            losers.erase(cur);
        }
        vector<int> ans;
        for (auto &a: losers) ans.push_back(a + 1);
        return ans;
    }
};
