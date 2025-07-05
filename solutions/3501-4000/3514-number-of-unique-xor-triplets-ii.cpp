class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> p, t;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                p.insert(nums[i] ^ nums[j]);
            }
        }

        for (auto &x: p) {
            for (auto &y: nums) {
                t.insert(x ^ y);
            }
        }
        return t.size();
    }
};
