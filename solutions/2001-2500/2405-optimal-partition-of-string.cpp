class Solution {
public:
    int partitionString(string s) {
        vector<int> cnt(26, 0);
        int ans = 1;
        for (int right = 0, left = 0; right < s.size(); right++) {
            cnt[s[right] - 'a']++;
            if (cnt[s[right] - 'a'] > 1) {
                ans++;
                while (left < right) {
                    cnt[s[left] - 'a']--;
                    left++;
                }
            }
            
        }
        return ans;
    }
};
