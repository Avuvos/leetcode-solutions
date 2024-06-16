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
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = (int) nums.size();
        SegmentTree st(n);
        
        auto is_peak = [&](int index) -> int {
            if (index == 0 || index == n - 1) {
                return 0;
            }
            if (nums[index] > nums[index - 1] && nums[index] > nums[index + 1]) {
                return 1;
            }
            return 0;
        };
        
        for (int i = 0; i < n; i++) {
            st.tree[i + n] = is_peak(i);
        }
        st.build();

        vector<int> ans;
        for (auto &query: queries) {
            int op = query[0];
            if (op == 1) {
                int l = query[1], r = query[2];
                ans.push_back(st.query(l + 1, r));
            } else if (op == 2) {
                int index = query[1], val = query[2];
                nums[index] = val;
                st.modify(index, is_peak(index));
                if (index + 1 < n) {
                    st.modify(index + 1, is_peak(index + 1));
                }
                if (index - 1 >= 0) {
                    st.modify(index - 1, is_peak(index - 1));
                }
            } else {
                assert(false);
            }
        }
        return ans;
    }
};
