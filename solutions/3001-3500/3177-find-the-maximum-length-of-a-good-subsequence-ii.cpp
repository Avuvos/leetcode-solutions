class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> tree;
        SegmentTree(int size) : n(size), tree(2 * size, 0) {}
        void build() {
            for (int i = n - 1; i > 0; i--) {
                tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
            }
        }
        
        void modify(int p, int value) {
            for (tree[p += n] = value; p > 1; p >>= 1) {
                tree[p >> 1] = max(tree[p], tree[p ^ 1]);
            }
        }
        
        int max_query(int l, int r) {
            int res = 0;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) {
                    res = max(res, tree[l]);
                    l++;
                }
                if (r & 1) {
                  r--;
                  res = max(res, tree[r]);  
                } 
            }
            return res;
        }
    };
    
    int dp[5001][51];
    int maximumLength(vector<int>& nums, int k) {
        int n = (int) nums.size(), ans = 1;
        vector<SegmentTree> seg_trees(k + 1, SegmentTree(n));
        unordered_map<int, int> num_to_dp;
        for (int j = 0; j <= k; j++) {
            num_to_dp.clear();  
            for (int i = 0; i < n; i++) {
                dp[i][j] = max(dp[i][j], 1 + num_to_dp[nums[i]]);
                if (j > 0) {
                    dp[i][j] = max(dp[i][j], 1 + seg_trees[j - 1].max_query(0, i));
                }
                num_to_dp[nums[i]] = max(num_to_dp[nums[i]], dp[i][j]);
                seg_trees[j].modify(i, dp[i][j]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
