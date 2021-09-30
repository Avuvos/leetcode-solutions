class Solution {
    public int getSum(int a, int b) {
        int carry;
        while (b != 0) { //we will store the result in a
            carry = a & b; //get the carry
            a = a ^ b; //xor is basically addition
            b = (carry) << 1; //shift the number
        }
        return a;
    }
}
