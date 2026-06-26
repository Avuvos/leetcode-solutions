class Solution {

// AI Generated helper class
class PrefixHash {
private:
    std::vector<long long> hash;
    std::vector<long long> power;
    const long long p = 11;         // A prime number close to the alphabet size
    const long long m = 1e9 + 9;    // A large prime modulo to prevent overflow

public:
    // O(N) Initialization
    PrefixHash(vector<int>& nums) {
        int n = nums.size();
        hash.assign(n + 1, 0);
        power.assign(n + 1, 1);

        // Precompute powers of p and prefix hashes
        for (int i = 0; i < n; ++i) {
            power[i + 1] = (power[i] * p) % m;
            hash[i + 1] = (hash[i] * p + nums[i]) % m;
        }
    }

    // O(1) Substring Hash Query (0-indexed, inclusive)
    long long get_hash(int L, int R) {
        long long res = (hash[R + 1] - (hash[L] * power[R - L + 1]) % m + m) % m;
        return res;
    }
};

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        PrefixHash ph(nums);

        auto ok = [&](int len) -> bool {
            map<long long, int> mp;
            for (int i = 0; i + len - 1 < n; i++) {
                long long cur = ph.get_hash(i, i + len - 1);
                mp[cur]++;
            }
            for (auto [key, val]: mp) {
                if (val == 1) {
                    return true;
                }
            }
            return false;
        };


        int l = 1, r = n, ans = n;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (ok(m)) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return ans;
    }
};
