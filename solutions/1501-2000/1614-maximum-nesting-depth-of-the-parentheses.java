class Solution {
    public int maxDepth(String s) {
        int res = 0;
        Stack<Integer> stack = new Stack<>();
        for (char c: s.toCharArray()) {
            if (c == '(') {
                stack.push(0);
                res = Math.max(res, stack.size());
            }
            else if (c == ')') {
                stack.pop();
            }
        }
        return res;
    }
}
