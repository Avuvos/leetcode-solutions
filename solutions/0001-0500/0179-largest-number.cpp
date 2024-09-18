class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> conv(n);
        for (int i = 0; i < n; i++) {
            conv[i] = to_string(nums[i]);
        }
        sort(conv.begin(), conv.end(), [&](const string& s1, const string& s2){
            string comb1 = s1 + s2;
            string comb2 = s2 + s1;
            return comb1 > comb2;
        });
        string ans;
        for (auto &s: conv) {
            ans += s;
        }
        reverse(ans.begin(), ans.end());
        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
