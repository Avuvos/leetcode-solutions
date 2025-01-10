class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), q = queries.size();
        sort(queries.begin(), queries.end());
        vector<int> ps(n + 1, 0);
        int used = 0;
        priority_queue<int> pq;
        for (int i = 0, j = 0; i < n; i++) {
            if (i > 0) {
                ps[i] += ps[i - 1];
            }
            nums[i] -= ps[i];
            while (j < q && queries[j][0] <= i) {
                pq.push(queries[j][1]);
                j++;
            }
            while (nums[i] > 0 && !pq.empty()) {
                int r = pq.top(); pq.pop();
                if (r < i) continue;
                ps[i] += 1;
                ps[r + 1] -= 1;
                nums[i] -= 1;
                used += 1;
            }
            if (nums[i] > 0) {
                return -1;
            }
        }
        return q - used;
    }
};
