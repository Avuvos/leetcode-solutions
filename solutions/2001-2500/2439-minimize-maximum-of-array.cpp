class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = (int) nums.size();
        int left = 0, right = (int)1e9, ans = (int)1e9;
        while (left <= right) {
            int mid = left + (right - left)/2;
            vector<long long> tmp;
            for (auto &num: nums) tmp.push_back(num);
            long long mx = 0;
            for (int i = n - 1; i > 0; i--) {
                if (tmp[i] > mid) {
                    long long delta = tmp[i] - mid;
                    tmp[i] -= delta;
                    tmp[i - 1] += delta;
                }
                mx = max(mx, tmp[i]);
            }
            mx = max(mx, tmp[0]);
            if (mx <= mid) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
