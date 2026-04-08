class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_map<char, int> freq;
        for (auto &c: s) freq[c]++;
        int ans = 0;
        for (auto [key, val]: freq) {
            char mirror = isdigit(key) ? ('9' - key + '0') : ('z' - key + 'a');
            bool mirror_exists = freq.contains(mirror);
            int mirror_val =  mirror_exists ? freq[mirror] : 0;
            if (key < mirror || !mirror_exists) {
                ans += abs(val - mirror_val);
            }
        }
        return ans;
    }
};
