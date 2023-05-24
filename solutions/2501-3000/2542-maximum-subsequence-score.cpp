class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int, int>> nums(n);
        for (int index = 0; index < n; index++) {
            nums[index] = {nums2[index], nums1[index]};
        }
        
        //sort by nums2 values in reverse order
        sort(nums.rbegin(), nums.rend());
        
        //init res, sum, minimum value and length of the sequence
        long long sum = nums[0].second, mn = nums[0].first, res = 0;
        int len = 1;
        
        //small edge case
        if (len == k)
            res = max(res, sum*mn);
        
        //init min heap
        priority_queue<int, vector<int>, greater<>> pq;
        pq.push(sum);
        
        for (int index = 1; index < n; index++) {
            //update sum and min
            mn = nums[index].first;
            sum += nums[index].second;
            
            //insert to heap and increase window size
            pq.push(nums[index].second);
            len++;
            
            //if the length is greater than k, pop the min value out of the heap
            if (len > k) {
                sum -= pq.top(); 
                pq.pop();
                len--;
            }
            
            //update the result
            if (len == k) {
                res = max(res, sum*mn);
            }
        }
        return res;
    }
};
