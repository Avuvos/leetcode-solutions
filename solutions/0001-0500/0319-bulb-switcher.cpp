class Solution {
public:
    int bulbSwitch(int n) {
        int ans = 0;
        for (int d = 1; d * d <= n; d++) {
            ans++;
        }
        return ans;
    }
};
