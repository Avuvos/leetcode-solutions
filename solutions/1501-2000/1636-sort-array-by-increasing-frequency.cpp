class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto x: nums) {
            mp[x]++;
        }
        sort(nums.begin(), nums.end(), [&](const int x, const int y){
           return mp[x] == mp[y] ? x > y : mp[x] < mp[y]; 
        });
        return nums;
    }
};
