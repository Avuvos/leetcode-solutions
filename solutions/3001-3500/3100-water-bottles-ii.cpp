class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = 0, empty = 0;
        while (numBottles > 0) {
            empty += numBottles;
            ans += numBottles;
            numBottles = 0;
            if (empty >= numExchange) {
                empty -= numExchange;
                numBottles += 1;
                numExchange += 1;
            } 
        }
        return ans;
    }
};
