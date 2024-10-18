class Solution {
public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> ans(n - k + 1);

        long long sum = 0;
        set<pair<int, int>> window, topx;
        map<int, int> freq;
        for (int i = 0; i < k; i++) {
            freq[nums[i]]++;
        }
        vector<pair<int, int>> values;
        for (auto [key, val]: freq) {
            values.push_back({val, key});
        }
        sort(values.rbegin(), values.rend());
        for (int i = 0; i < (int)values.size(); i++) {
            if (i >= x) {
                window.insert(values[i]);
            } else {
                topx.insert(values[i]);
                sum += 1LL * values[i].first * values[i].second;
            }
        }
        
        auto add_to_topx = [&](int cf, int cv) -> void {
            topx.insert({cf, cv});
            sum += 1LL * cf * cv;
            window.erase({cf, cv});
        };

        auto rebalance = [&]() -> void {
            if (window.empty()) return;
            auto [cf, cv] = *window.rbegin();
            if (topx.size() < x) {
                add_to_topx(cf, cv);
            } else if (topx.begin() -> first < cf || (topx.begin() -> first == cf && topx.begin() -> second < cv)) {
                sum -= 1LL * topx.begin() -> first * topx.begin() -> second;
                window.insert(*topx.begin());
                topx.erase(topx.begin());
                add_to_topx(cf, cv);
            }
        };
        
        auto add = [&](int index) -> void {
            int v = nums[index];
            if (topx.find({freq[v], v}) != topx.end()) {
                topx.erase({freq[v], v});
                freq[v]++;
                sum += v;
                topx.insert({freq[v], v});
            } else {
                window.erase({freq[v], v});
                freq[v]++;
                window.insert({freq[v], v});
                rebalance();
            }
        };

        auto rem = [&](int index) -> void {
            int v = nums[index];
            if (window.find({freq[v], v}) != window.end()) {
                window.erase({freq[v], v});
                freq[v]--;
                if (freq[v] > 0) {
                    window.insert({freq[v], v});
                }
            } else {
                topx.erase({freq[v], v});
                sum -= v;
                freq[v]--;
                if (freq[v] > 0) {
                    topx.insert({freq[v], v});
                }
                rebalance();
            }
        };
        

        ans[0] = sum;
        for (int i = k; i < n; i++) {
            rem(i - k);
            add(i);
            ans[i - k + 1] = sum;
        }
        return ans;
    }
};
