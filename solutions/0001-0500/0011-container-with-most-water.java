class Solution {
    public static int maxArea(int[] height) {
        int res = 0;
        int left = 0;
        int right = height.length-1;
        
        while (left < right) {
            int y = Math.min(height[left], height[right]);
            int x = right - left;
            int currArea = x * y;
            res = Math.max(res, currArea);
            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return res;
    }
}
