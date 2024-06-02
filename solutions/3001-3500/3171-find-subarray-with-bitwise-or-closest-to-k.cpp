const int N = 2e5 + 14;  // limit for array size
int n;  // array size
int tree[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) {
        tree[i] = tree[i << 1] & tree[i << 1 | 1];
    }
}

void modify(int p, int value) {  // set value at position p
    for (tree[p += n] = value; p > 1; p >>= 1) {
        tree[p >> 1] = tree[p] & tree[p ^ 1];
    }
}

int query(int l, int r) {  // sum on interval [l, r)
    int res = -1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res = (res == -1 ? tree[l] : (res & tree[l]));
            l++;
        }
        if (r & 1) {
            r--;
            res = (res == -1 ? tree[r] : (res & tree[r]));
        }
    }
    return res;
}

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            tree[i + n] = nums[i];
        }
        int ans = abs(nums[0] - k);
        build();
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int val = query(i, mid);
                ans = min(ans, abs(val - k));
                if (val > k) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return ans;
    }
};
