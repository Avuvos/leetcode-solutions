class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        for (int i = 2; i < n; i++) {
            //cout << nums[i] << " " << nums[i - 1] << '\n';
            if (nums[i - 1] <= nums[i - 2]) left[i] = 1 + left[i - 1];
        }
        for (int i = n - 3; i >= 0; i--) {
            if (nums[i + 1] <= nums[i + 2]) right[i] = 1 + right[i + 1];
        }
        vector<int> res;
        for (int index = k; index < n - k; ++index) {
            //cout << left[index] << " " << right[index] << '\n';
            if (left[index] >= k && right[index] >= k) {
                res.push_back(index);
            }
        }
        return res;
    }
};
