class Solution {
public:
    int rev_bin(int x) {
        string s = bitset<32>(x).to_string();
        s = s.substr(s.find('1'));
        reverse(s.begin(), s.end());
        return stoi(s, nullptr, 2);
    };

    vector<int> sortByReflection(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto &x: nums) mp[x] = rev_bin(x);

        sort(nums.begin(), nums.end(), [&](int x, int y) {
            int bx = mp[x], by = mp[y];
            return bx == by ? x < y : bx < by;
        });
        
        return nums;
    }
};
