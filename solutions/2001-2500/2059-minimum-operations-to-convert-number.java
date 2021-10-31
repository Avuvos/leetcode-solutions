class Solution {
    public int minimumOperations(int[] nums, int start, int goal) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        int res = 0;
        Set<Integer> visited = new HashSet<>();
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int num = q.poll();
                if (visited.contains(num) || num < 0 || num > 1000) {
                    continue;
                }
                visited.add(num);
                for (int n: nums) {
                    if (num + n == goal || num - n == goal || (num ^ n) == goal)
                        return res + 1;
                    if (num + n >= 0 && num - n <= 1000) q.offer(num + n);
                    if (num - n >= 0 && num - n <= 1000) q.offer(num - n);
                    if ((num^n) >= 0 && (num^n) <= 1000) q.offer(num ^ n);
                }
                
            }
            res++;
        }
        return -1;
    }
}
