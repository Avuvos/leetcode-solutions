class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        int n = word.size(), cnt = 0;
        long long ans = 0;
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        vector<vector<int>> ps(5);
        // unordered_map<char, vector<int>> ps;
        for (int j = 0; j < 5; j++) {
            ps[j].resize(n + 1);
            for (int i = 0; i < n; i++) {
                ps[j][i + 1] = ps[j][i] + (word[i] == vowels[j] ? 1 : 0);
            }
        }
        
        auto check = [&](int l, int r) -> pair<bool, int> {
            int cnt_vowels = 0;
            bool found_all_vowels = true;
            for (int i = 0; i < 5; i++) {
                vector<int> &vec = ps[i];
                int cur = vec[r + 1] - vec[l];
                if (cur == 0) found_all_vowels = false;
                cnt_vowels += cur;
            }
            // cout << l << " " << r << " " << found_all_vowels << " " << length <<  " " << length - cnt_vowels << '\n';
            return {found_all_vowels, r - l + 1 - cnt_vowels};
        };
        
        for (int l = 0; l < n; l++) {
            int left = l, right = n - 1, res_right = -1, res_left = n + 1;
            map<pair<int, int>, pair<bool, int>> memo;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                auto [ok, c] = check(l, mid);
                if (c == k && ok) {
                    res_right = max(res_right, mid);
                }
                if (c <= k) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (res_right == -1) continue;
            left = l, right = res_right;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                auto [ok, c] = check(l, mid);
                if (c == k && ok) {
                    res_left = min(res_left, mid);
                }
                if (c < k || (c == k && !ok)) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            if (res_left == n + 1) continue;
            ans += (res_right - res_left + 1);
        }
        
        return ans;
    }
};
