class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) {
            return false;
        }
        multiset<int> ms(nums.begin(), nums.end());
        while (!ms.empty()) {
            int current = *ms.begin();
            ms.erase(ms.begin());
            int sz = 1;
            while (sz < k) {
                auto it = ms.upper_bound(current);
                if (it == ms.end() || *it - current > 1) {
                    return false;
                }
                current = *it;
                ms.erase(it);
                sz++;
            }
        }
        return true;
    }
};
