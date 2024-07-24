class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto convert = [&](int x) -> int {
            string s = to_string(x);
            int res = 0;
            for (auto &d: s) {
                res *= 10;
                res += mapping[d - '0'];
            }
            return res;
        };
        unordered_map<int, int> real_map;
        for (auto &x: nums) {
            real_map[x] = convert(x);
        }
        sort(nums.begin(), nums.end(), [&](const int x, const int y) {
           return real_map[x] < real_map[y]; 
        });
        return nums;        
    }
};
