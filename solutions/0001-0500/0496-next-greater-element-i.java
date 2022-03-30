class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> stack = new Stack<>();
        Map<Integer, Integer> map = new HashMap<>();
        int n = nums1.length, m = nums2.length;
        int [] ans = new int[n];
        
        for (int i = m - 1; i >= 0; i--) {
            int curr = nums2[i];
            while (!stack.isEmpty() && stack.peek() < curr) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                map.put(curr, -1);
                stack.push(curr);
                continue;
            }
            map.put(curr, stack.peek());
            stack.push(curr);
        }
        for (int j = 0; j < n; j++) {
            ans[j] = map.get(nums1[j]);
        }
        return ans; 
    }
}
