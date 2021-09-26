class Solution {
    public boolean backspaceCompare(String s, String t) {
        return stringToStack(s).equals(stringToStack(t));
    }
    
    public String stringToStack(String a) {
        Stack<Character> stk = new Stack<>();
        for (int i=0; i<a.length(); i++) {
            if (a.charAt(i) != '#') {
                stk.push(a.charAt(i));
            }
            else {
                if (!stk.isEmpty()) stk.pop();
            }
        }
        return stk.toString();
    }
}
