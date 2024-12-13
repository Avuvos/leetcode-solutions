class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = (int) nums.size();
        
        auto valid = [&](int i, bool left) -> bool {
            auto a = nums;
            if (a[i] == 0) {
                while (i >= 0 && i < n) {
                    if (a[i] > 0) {
                        a[i]--;
                        left = !left;
                    }
                    i = i + (left ? -1 : 1);
                }
            }
            return all_of(a.begin(), a.end(), [&](int x) {return x == 0;});
        };
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (valid(i, true)) {
                ans++;
            }
            if (valid(i, false)) {
                ans++;
            }
        }
        return ans;
    }
};
