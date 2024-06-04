class Solution {
public:
    //we can reach the range [0, cur]
    //can we reach cur + 1?
    //yes if the current coin is <= cur + 1
    //since if it is, then there is x in [0, cur] such that x + coin = cur + 1
    //so we update the range to be [0, cur + coin]
    //otherwise we cant reach cur + 1, so we add cur + 1 to the list, update the answer,
    //and now we can reach [0, cur + cur + 1] = [0, 2*cur + 1]
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        int cur = 0, ans = 0;
        int i = 0;
        while (cur < target) {
            if (i >= coins.size() || coins[i] > cur + 1) {
                ans++;
                cur = 2*cur + 1;
            } else {
                cur += coins[i];
                i++;
            }
        }
        return ans;
    }
};
