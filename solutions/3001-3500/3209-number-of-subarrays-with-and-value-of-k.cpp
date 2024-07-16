class Solution {
public:
    struct SegmentTree {
        int n;
        vector<int> tree;
        SegmentTree(int size) : n(size), tree(2 * size, 0) {}
        void build() {
            for (int i = n - 1; i > 0; i--) {
                tree[i] = tree[i << 1] & tree[i << 1 | 1];
            }
        }

        void modify(int p, int value) {
            for (tree[p += n] = value; p > 1; p >>= 1) {
                tree[p >> 1] = tree[p] & tree[p ^ 1];
            }
        }

        int query(int l, int r) {
            int res = (1 << 30) - 1;
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) {
                    res &= tree[l];
                    l++;
                }
                if (r & 1) {
                    r--;
                    res &= tree[r];
                }
            }
            return res;
        }
    };
    long long countSubarrays(vector<int>& nums, int k) {
        int n = (int) nums.size();
        SegmentTree st(n);
        for (int i = 0; i < n; i++) {
            st.tree[i + n] = nums[i];
        }
        st.build();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int left = n, right = -1;
            
            int l = i, r = n - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (st.query(i, m + 1) <= k) {
                    left = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            
            l = i, r = n - 1;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (st.query(i, m + 1) >= k) {
                    right = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            if (left <= right && st.query(i, left + 1) == k && st.query(i, right + 1) == k) {
                ans += right - left + 1;
            }
            
        }
        
        return ans;
        
    }
};
