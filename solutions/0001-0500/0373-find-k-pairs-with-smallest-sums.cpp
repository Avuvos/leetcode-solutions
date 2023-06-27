class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> next_index(nums1.size(), 1);
        for (int i = 0; i < nums1.size(); i++) {
            pq.push({nums1[i] + nums2[0], i});
        }
        
        while (!pq.empty() && ans.size() < k) {
            auto [val, idx] = pq.top(); pq.pop();
            int next_idx = next_index[idx];
            ans.push_back({nums1[idx], nums2[next_idx - 1]});
            if (next_idx < nums2.size()) {
                pq.push({nums2[next_idx] + nums1[idx] ,idx});
                next_index[idx]++;
            }
        }
        return ans;
    }
};
