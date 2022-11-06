typedef long long ll;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll res = 0, left = 0, sum = 0;
        unordered_set<ll> s;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while ( (left < right && s.find(nums[right]) != s.end()) || right - left + 1 > k) {
                s.erase(s.find(nums[left]));
                sum -= nums[left];
                left++;
            }
            s.insert(nums[right]);
            if (right - left + 1 == k) 
                res = max(res, sum);
        }
        return res;
    }
};
