typedef long long ll;
class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        //if we got 2^0, 2^1, .. 2^i, then every number from [1 to 2^i+1) is reachable
        ll p = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == p) {
                p <<= 1;
            } else if (nums[i] > p) {
                return p;
            }
        }
        return p;
        
    }
};
