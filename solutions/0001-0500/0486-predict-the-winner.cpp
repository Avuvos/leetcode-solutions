class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        function<int(int, int, int)> dfs = [&](int l, int r, int player) {
            if (l > r) {
                return 0;
            }
            if (player == 0) {
                return max(nums[l] + dfs(l + 1, r, player ^ 1),
                           nums[r] + dfs(l, r - 1, player ^ 1)); 
            } else {
                return min(-nums[l] + dfs(l + 1, r, player ^ 1),
                           -nums[r] + dfs(l, r - 1, player ^ 1));
            }
        };
        
        int ans = dfs(0, nums.size() - 1, 0);
        return ans >= 0;
    } 
};
