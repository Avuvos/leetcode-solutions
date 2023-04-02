class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(), m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int left = 0, right = m - 1, pos = m;
            while (left <= right) {
                int mid = left + (right - left)/2;
                if ((long long)potions[mid] * spells[i] >= success) {
                    pos = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = m - pos;
        }
        return ans;
    }
};
