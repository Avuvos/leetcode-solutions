class Solution {
    public String minRemoveToMakeValid(String s) {
        Stack<Integer> stack = new Stack<>();
        StringBuilder res = new StringBuilder(s);
        for (int i=0; i<s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            }
            if (s.charAt(i) == ')') {
                if (stack.isEmpty()) {
                    res.setCharAt(i, '*');
                }
                else {
                    stack.pop();
                }
            }
        }
        while (!stack.isEmpty()) {
            res.setCharAt(stack.pop(), '*');
        }
        return res.toString().replaceAll("\\*", "");
    }
}
