typedef long long ll;
class Solution {
public:
    ll memo[101][101][101];
    ll INF = 1e18;
    ll dfs(int r, int f, int amt, vector<int>& robot, vector<vector<int>>& factory) {
        if (r >= robot.size()) return 0; //no robots left we are done
        if (memo[r][f][amt]) return memo[r][f][amt]; //memoization

            
        ll res = INF, cur = INF;
        
        if (amt > 0) //place robot to the current factory
            cur = dfs(r + 1, f, amt - 1, robot, factory) + abs(robot[r] - factory[f][0]);
        
        if (f + 1 < factory.size()) //skip the current factory
            cur = min(cur, dfs(r, f + 1, factory[f + 1][1], robot, factory));
        
        res = min(res, cur);
        memo[r][f][amt] = res;
        return res;
    }
    
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        return dfs(0, 0, factory[0][1], robot, factory);
    }
};
