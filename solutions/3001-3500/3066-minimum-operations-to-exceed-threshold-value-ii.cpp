class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long long> ms;
        for (auto &x: nums) ms.insert(x);
        
        int ans = 0;
        while (ms.size() > 1) {
            long long first = *ms.begin();
            if (first >= k) break;
            ms.erase(ms.find(first));
            long long second = *ms.begin();
            ms.erase(ms.find(second));
            ans++;
            long long mn = min(first, second);
            long long mx = max(first, second);
            ms.insert(mn*2 + mx);
        }
        return ans;
        
    }
};
