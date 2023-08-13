class Solution {
public:
    typedef long long ll;
    //after this sieve:
    // min_prime[x] = p > 0 means p is the smallest prime that divides x
    // min_prime[x] = -1 means x is a prime
    // min_prime[x] = -2 means x is either 0 or 1
    ll expo(ll a, ll b, ll m) {
        ll res = 1;
        if (b == 0) return res;
        while (b > 0) {
            if (b & 1) {
                res *= a;
                res %= m;
            }
            a *= a;
            a %= m;
            b >>= 1;
        }
        return res;
    }

    ll inverse(ll a, ll mod){
        return expo(a , mod-2 , mod);
    }

    vector<int> min_prime;
    int N = 1e5 + 14;
    void sieve(int n) {
        min_prime =vector<int>(n + 1, -1);
        min_prime[0] = min_prime[1] = -2;
        for (int i = 2; i * i <= n; i++) {
            if (min_prime[i] == -1) {
                for (int j = i * i; j <= n; j += i)
                    min_prime[j] = i;
            }
        }
    }
    const int MOD = 1e9 + 7;
    int maximumScore(vector<int>& nums, int k) {
        if (min_prime.empty()) {
            sieve(N);
        }
        int n = (int) nums.size();
        vector<int> dom(n);
        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++) {
            int x = nums[i], score = 0;
            while (x > 1) {
                int p = min_prime[x];
                if (p == -1) p = x;
                score++;
                while (x % p == 0) x /= p;
            }
            a.emplace_back(score, i);
            dom[i] = score;
        }
        
        sort(a.begin(), a.end(), [&](const pair<int, int> &a, const pair<int, int> &b) {
            if (nums[a.second] != nums[b.second]) {
                return nums[a.second] > nums[b.second];
            }
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        ll ans = 1;
        for (auto [score, index]: a) {
            int low = index, high = index;
            while (low - 1 >= 0 && dom[low - 1] < score) {
                low--;
            }
            if (low == -1) low++;
            while (high + 1 < n && dom[high + 1] <= score) {
                high++;
            }
            ll subarrays = 1LL * (high - index + 1) * (index - low + 1);
            ll take = min((ll) k, subarrays);
            ans *= expo(nums[index], take, MOD);
            ans %= MOD;
            k -= take;
            if (k == 0) break;
        }
        return ans % MOD;
    }
};
