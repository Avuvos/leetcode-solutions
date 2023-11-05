typedef long long ll;
const int N = 3e5 + 17;  // limit for array size
int n;  // array size
ll maximum[2 * N];

void build() {  // build the tree
    for (int i = n - 1; i > 0; --i) {
        maximum[i] = max(maximum[i << 1], maximum[i << 1 | 1]);
    }
}

void modify(int p, ll value) {  // set value at position p
    for (maximum[p += n] = value; p > 1; p >>= 1) {
        maximum[p >> 1] = max(maximum[p], maximum[p ^ 1]);
    }
}

ll max_query(int l, int r) {  // max on interval [l, r)
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            res = max(res, maximum[l]);
            l++;
        }
        if (r & 1) {
            r--;
            res = max(res, maximum[r]);
        }
    }
    return res;
}


class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        n = (int) nums.size();
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++) {
            maximum[i + n] = -1e9;
        }
        build();
        
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](const int i, const int j) {
           return nums[i] - i < nums[j] - j; 
        });
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int idx = order[i];
            mp[nums[idx] - idx] = i;
        }
        for (int i = 0; i < n; i++) {
            int cur = nums[i] - i;
            dp[i] = nums[i] + max_query(0, mp[cur] + 1);
            //we want query max on all elements that have diff <= cur
            //find the max dp value of all elements that have diff <= cur
            modify(mp[cur], dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
