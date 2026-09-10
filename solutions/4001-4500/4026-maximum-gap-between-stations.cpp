class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> left(n), right(n);
        for (int i = 0, j = 0; i < m && j < n; i++) {
            if (skill[j] == station[i]) {
                left[j] = i;
                j++;
            }
        }
        for (int i = m - 1, j = n - 1; i >= 0 && j >= 0; i--) {
            if (skill[j] == station[i]) {
                right[j] = i;
                j--;
            }
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (left[i - 1] < right[i]) {
                ans = max(ans, right[i] - left[i - 1]);
            }
        }
        return ans;

    }
};
