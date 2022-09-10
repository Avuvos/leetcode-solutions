class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> idxes(nums.size());
        iota(idxes.begin(), idxes.end(), 0);
        sort(idxes.begin(), idxes.end(), [&](int a, int b) {
            return nums[a] > nums[b];});
        idxes.resize(k);
        sort(idxes.begin(), idxes.end());
        vector<int> res;
        for (auto index: idxes) res.push_back(nums[index]);
        return res;
    }
};
