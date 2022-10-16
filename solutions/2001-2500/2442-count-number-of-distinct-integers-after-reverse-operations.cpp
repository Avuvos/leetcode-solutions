class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto num: nums) {
            vector<int> curr;
            while (num > 0) {
                curr.push_back(num % 10);
                num /= 10;
            }
            int rev = 0;
            reverse(curr.begin(), curr.end());
            for (int i = 0; i < curr.size(); i++) {
                rev += curr[i] * pow(10, i);
            }
            s.insert(rev);
        }
        return s.size();
    }
};
