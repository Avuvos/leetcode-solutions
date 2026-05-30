class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int z = find(nums.begin(), nums.end(), 0) - nums.begin();
        bool inc = true, dec = true;
        for (int i = 0; i < n; i++) {
            inc = inc && (nums[(i + z) % n] == i);
            dec = dec && (nums[(i + z) % n] == (n - i) % n);
        }
        if (inc) {
            return min(z, n - z + 2);
        }
        if (dec) {
            return min(z + 2, n - z - 1 + 1);
        }
        return -1;
    }
};
