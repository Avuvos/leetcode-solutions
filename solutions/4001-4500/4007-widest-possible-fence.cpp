class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int ans = 0;
        unordered_map<int, int> cnt, width;
        for (auto &p: planks) {
            cnt[p]++;
            width[p]++;
            ans = max(ans, width[p]);
        }
        for (auto &[k1, v1]: cnt) {
            for (auto &[k2, v2]: cnt) {
                if (k1 > k2) continue;
                int cur = k1 == k2 ? v1 / 2 : min(v1, v2);
                width[k1 + k2] += cur;
                ans = max(ans, width[k1 + k2]);
            }
        }
        return ans;
    }
};
