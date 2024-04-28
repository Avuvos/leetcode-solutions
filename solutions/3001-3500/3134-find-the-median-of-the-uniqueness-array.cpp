class Solution {
public:
    int medianOfUniquenessArray(vector<int>& nums) {
        int n = (int) nums.size();
        long long m = 1LL * n * (n + 1) / 2;
        //bs on the answer, let it be x
        //then we can try to find how many subarrays there are with uniqueness that is <= x?
        //if that number is too small we know the answer is greater than x, otherwise its x or smaller than x.
        //we compare what we find with n(n+1)/2 which is the size of the uniqueness array ofc.
        
        //returns the number of subarrays which have value <= k using sliding window
        auto get = [&](int k) -> long long {
            unordered_map<int, int> mp;
            long long res = 0;
            for (int r = 0, l = 0; r < n; r++) {
                mp[nums[r]]++;
                while ((int)mp.size() > k) {
                    if (--mp[nums[l]] == 0) {
                        mp.erase(nums[l]);
                    }
                    l++;
                }
                res += (r - l + 1);
            }
            return res;
        };
        
        long long bound = (m + 1) / 2;
        int left = 1, right = n + 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            long long current = get(mid);
            if (current >= bound) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
