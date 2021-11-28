class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        if (n == 0) {
            return;
        }
        
        else if (m == 0) {
            for (int i=0; i<nums1.length; i++){
                nums1[i] = nums2[i];
            }
        }
        
        else {
            int a = m-1; //for nums1
            int b = n-1; //for nums2

            for (int i=nums1.length-1; i>=0; i--) {
                if (a >= 0 && b >=0 ) {
                    if (nums1[a] > nums2[b]) 
                        nums1[i] = nums1[a--];
                    else 
                        nums1[i] = nums2[b--];
                }
                else if 
                    (a >= 0) nums1[i] = nums1[a--];
                else 
                    nums1[i] = nums2[b--];
            }    
        }
    }
}


