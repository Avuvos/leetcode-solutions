class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long ans = 0;
        while (pq.top() > 1 && k--) {
            int x = pq.top(); pq.pop();
            ans += x;
            pq.push((x + 2) / 3);
        }
        ans += max(0, k);
        return ans;
    }
};
