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
    long long numberOfSubarrays(vector<int>& nums) {
        //for some value v, binary search the right-most value v such that the subarray is valid..
        //for that we just need a segtree max?
        n = (int) nums.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maximum[i + n] = nums[i];  
        }
        build();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            auto &v = mp[nums[i]];
            int index = lower_bound(v.begin(), v.end(), i) - v.begin();
            
            int left = index, right = v.size() - 1, res = i;
            
            while (left <= right) {
                int mid = left + (right - left)/2;
                if (max_query(i, v[mid] + 1) == nums[i]) {
                    res = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
           
            ans += (res - index + 1);
        }
        return ans;
    }
};
