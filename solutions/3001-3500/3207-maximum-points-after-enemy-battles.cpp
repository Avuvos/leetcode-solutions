class Solution {
public:
    long long maximumPoints(vector<int>& a, int currentEnergy) {
        int n = (int) a.size();
        sort(a.begin(), a.end());
        long long en = currentEnergy;
        if (en < a[0]) {
            return 0;
        }
        en -= a[0];
        for (int i = 1; i < n; i++) en += a[i];
        long long ans = en / a[0];
        for (int i = 1; i < n; i++) {
            en -= a[i];
            ans = max(ans, (long long) i + en / a[0]);
        }
        
        return 1 + ans;
    }
};
