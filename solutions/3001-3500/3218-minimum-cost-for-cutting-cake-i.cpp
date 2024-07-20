class Solution {
public:
    int minimumCost(int m, int n, vector<int>& hc, vector<int>& vc) {
        sort(hc.rbegin(), hc.rend());
        sort(vc.rbegin(), vc.rend());
        m--;
        n--;
        int i = 0, j = 0;
        long long ans = 0;
        int hp = 1, vp = 1;
        while (i < m && j < n) {
            if (hc[i] > vc[j]) {
                ans += vp * hc[i];
                hp++;
                i++;
            } else {
                ans += hp * vc[j];
                vp++;
                j++;
            }
        }
        while (i < m) {
            ans += vp * hc[i];
            i++;
        }
        while (j < n) {
            ans += hp * vc[j];
            j++;
        }
        return ans;
    }
};
