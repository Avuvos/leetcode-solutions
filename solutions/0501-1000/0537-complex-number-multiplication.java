class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        String result = "";
        String[] A = num1.split("\\+");
        String[] B = num2.split("\\+");
        int a = Integer.parseInt(A[0]);
        int b = Integer.parseInt(A[1].replace("i", ""));
        int c = Integer.parseInt(B[0]);
        int d = Integer.parseInt(B[1].replace("i", ""));
        int first = (a*c - b*d);
        String firstP = first + "";
        int second = (a*d + b*c);
        String secondP = second + "i";
        result = firstP + "+" + secondP;
        return result;
        
    }
}
