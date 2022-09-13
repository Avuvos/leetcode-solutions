class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto a: nums) {
            cnt[a]++;
        }
        int best_cnt = 0;
        for (auto [key, val]: cnt) {
            if (key % 2 == 0)
                best_cnt = max(best_cnt, val);
        }
        int min_elem = INT_MAX;
        for (auto [key, val]: cnt) {
            if (key % 2 == 0 && val == best_cnt) {
                if (key < min_elem)
                    min_elem = key;
            }
        }
        return min_elem != INT_MAX ? min_elem : -1;
    }
};
