class Solution {
public:

    static const int N = 4e4 + 12;
    static const int BITS = 15;

    struct Node {
        int child[2];
        int count;
    } trie[N * BITS * 2];

    int roots[N];
    int node_count = 0;

    int insert(int prev_root, int val) {
        int new_root = ++node_count;
        int curr = new_root;
        trie[curr] = trie[prev_root];
        trie[curr].count++;
        for (int i = BITS; i >= 0; i--) {
            int bit = (val >> i) & 1;

            trie[curr].child[bit] = ++node_count;
            trie[trie[curr].child[bit]] = trie[trie[prev_root].child[bit]];

            curr = trie[curr].child[bit];
            prev_root = trie[prev_root].child[bit];

            trie[curr].count++;

        }
        return new_root;
    }

    int query(int left_root, int right_root, int val) {
        int max_xor = 0;
        for (int i = BITS; i >= 0; i--) {
            int bit = (val >> i) & 1;
            int desired = 1 - bit;
            if (trie[trie[right_root].child[desired]].count - 
                trie[trie[left_root].child[desired]].count > 0) {
                max_xor |= (1 << i);
                right_root = trie[right_root].child[desired];
                left_root = trie[left_root].child[desired];
            } else {
                right_root = trie[right_root].child[bit];
                left_root = trie[left_root].child[bit];
            }
        }
        return max_xor;
    }
    
    int maxXor(vector<int>& nums, int k) {
        int n = nums.size(), ps = 0, ans = 0;
        multiset<int> ms;
        roots[0] = insert(0, 0);
        for (int r = 0, l = 0; r < n; r++) {
            ps ^= nums[r];
            roots[r + 1] = insert(roots[r], ps);
            ms.insert(nums[r]);
            while (*ms.rbegin() - *ms.begin() > k) {
                ms.erase(ms.find(nums[l]));
                l++;
            }
            int left_root = (l == 0) ? 0 : roots[l - 1];
            ans = max(ans, query(left_root, roots[r + 1], ps));
        }
        return ans;
    }
};
