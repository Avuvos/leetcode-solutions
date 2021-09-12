class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> stack = new Stack<Integer>();
        int res = 0;
        
        for (String s: ops) {
            if (s.equals("C")) {
                stack.pop();
            }
            
            else if (s.equals("D")) {
                int prev = stack.peek();
                stack.push(prev*2);
            }
            
            else if (s.equals("+")) {
                int n1 = stack.pop();
                int n2 = stack.peek();
                int n3 = n1 + n2;
                stack.push(n1);
                stack.push(n3);
            }
            
            else {
                int n = Integer.parseInt(s);
                stack.push(n);
            }
        }
        
        while (!stack.isEmpty()) {
            res += stack.pop();
        }
        return res;
    }
}
