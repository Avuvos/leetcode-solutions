class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = (int) nums.size();
        int pivot = nums[rand() % n];
        vector<int> small, big, eq;
        for (auto x: nums) {
            if (x > pivot) big.push_back(x);
            else if (x < pivot) small.push_back(x);
            else eq.push_back(x);
        }
        int bigSz = (int) big.size(), eqSz = (int) eq.size();
        if (k <= bigSz) {
            return findKthLargest(big, k);
        }
        if (bigSz + eqSz < k) {
            return findKthLargest(small, k - bigSz - eqSz);
        }
        return pivot; 
    }
};
