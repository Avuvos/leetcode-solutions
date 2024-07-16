class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = (int) colors.size();
        int ans = 0;
        for (int l = 0, r = 0; r < n + k - 1; r++) {
            if (r - l + 1 >= k) { 
                ans++;
            }
            if (colors[r % n] == colors[(r + 1) % n]) {
                l = r + 1;
            }
            
        }
        return ans;
    }
};
