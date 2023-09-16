class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int n = (int) nums.size();
        int ans = n;
        map<int, int> mp;
        for (auto x: nums) mp[x]++;
        priority_queue<int> pq;
        for (auto [key, val]: mp) {
            pq.push(val);
        }
        while (pq.size() > 1) {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            x--, y--;
            ans -= 2;
            if (x > 0)
                pq.push(x);
            if (y > 0)
                pq.push(y);
        }
        return ans;
    }
};
