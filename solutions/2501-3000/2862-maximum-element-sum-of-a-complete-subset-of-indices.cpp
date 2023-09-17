class Solution {
public:
    typedef long long ll;
    long long maximumSum(vector<int>& nums) {
        int n = (int) nums.size();
        vector<int> parent(n + 1, 0), sz(n + 1, 0);
        vector<ll> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = nums[i - 1];
            parent[i] = i;
        }
        
        function<int(int)> find_ = [&](int x) {
            return x == parent[x] ? x : parent[x] = find_(parent[x]);
        };
        
        auto union_ =[&](int x,int y) {
            int X = find_(x), Y = find_(y);
            if (X == Y) return false;
            if (sz[X] < sz[Y]) swap(X, Y);
            parent[Y] = X;
            sz[X] += sz[Y];
            sum[X] += sum[Y];
            return true;
        };
        
        auto perfect_square = [&](ll x) -> bool {
            ll z = (ll) sqrt(x);
            return z * z == x;
        };
        
        for (ll x = 1; x <= n; x++) {
            ll y = x * x;
            for (ll d = 1; d * d <= y; d++) {
                if (y % d == 0) {
                    ll d2 = y / d;
                    if (d <= n && d2 <= n) {
                        union_(d, d2);
                    }
                }
            }
        }

        return *max_element(sum.begin(), sum.end());
    }
};
