class Solution {
public:
    struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int size) : n(size), tree(2 * size, 0) {}
    void build() {
        for (int i = n - 1; i > 0; i--) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    void modify(int p, int value) {
        for (tree[p += n] = value; p > 1; p >>= 1) {
            tree[p >> 1] = tree[p] + tree[p ^ 1];
        }
    }

    int query(int l, int r) {
        int res = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                res += tree[l];
                l++;
            }
            if (r & 1) {
                r--;
                res += tree[r];
            }
        }
        return res;
    }
};
    
    vector<int> countSmaller(vector<int>& nums) {
        const int maxN = 3e4, add = 1e4;
        SegmentTree st(maxN);
        int n = (int) nums.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            nums[i] += add;
            ans[i] = st.query(0, nums[i]);
            st.modify(nums[i], 1 + st.query(nums[i], nums[i] + 1));
        }
        return ans;
    }
};
