class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        dfs(res, n, n, "");
        return res;
    }
    
    
    public void dfs(List<String> res, int open, int closed, String curr) {
        if (open == 0 && closed == 0) {
            res.add(curr);
            return;
        }
        if (open > 0) {
            dfs(res, open-1, closed, curr + "(");
        }
        if (open < closed && closed > 0) {
            dfs(res, open, closed-1, curr + ")");
        }
    }
}
