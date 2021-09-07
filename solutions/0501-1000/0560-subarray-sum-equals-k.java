class Solution {
    public int subarraySum(int[] nums, int k) {
        int cnt = 0;
        int currSum = 0;
        Map<Integer, Integer> map = new HashMap<Integer,Integer>();
        map.put(currSum, 1);
        
        for (int i=0; i<nums.length; i++) {
            currSum += nums[i];
            if (map.containsKey(currSum - k)) 
                cnt += map.get(currSum - k);
            
            map.put(currSum, map.getOrDefault(currSum, 0) + 1);
            
        }
        return cnt;
    }
}
