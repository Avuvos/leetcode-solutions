class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        map<int, int> freq, ps;
        set<int> cands;
        for (auto &x: nums) {
            freq[x]++;
            ps[x - k]++;
            ps[x + k + 1]--;
            cands.insert(x - k);
            cands.insert(x);
            cands.insert(x + k + 1);
        }
        
        int best = 0, len = 0;
        for (auto &x: cands) {
            len += ps[x];
            int current = freq[x] + min(len - freq[x], numOperations);
            best = max(best, current);
        }
        return best;
    }
};
