class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int [n];
        int[] prod = new int [n];
        Arrays.fill(prod, 1);
        prod[0] = nums[0];
        
        for (int i=1; i<n; i++) {
            prod[i] = prod[i-1]*nums[i];
        }
        
        int ReversedProd = 1;
        //basically to find answer[i=2] for example in [1,2,3,4,5]
        //we do (1*2) * (5*4) 
        //which is prod[i-1] multiplied by ReversedProduct
        for (int i=n-1; i>=0; i--) {
            if (i == n - 1) {
                answer[i] = prod[n-2];
            }
            else if (i == 0) {
                answer[i] = ReversedProd;
            }
            else {
                answer[i] = prod[i-1]*ReversedProd;
            }     
            ReversedProd *= nums[i];
        }
        
        return answer;
    }
}
