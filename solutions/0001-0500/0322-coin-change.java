class Solution {
    public int coinChange(int[] coins, int amount) {
        if (amount == 0) return 0;
        Queue<Integer> q = new LinkedList<>();
        for (int c: coins) {
            if (c > amount) continue;
            q.offer(c);
        }
        
        boolean[] visited = new boolean[amount + 1];
        int steps = 1;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int num = q.poll();
                if (num == amount) {
                    return steps;
                }
                if (num > amount || visited[num]) {
                    continue;
                }
                visited[num] = true;
                for (int c: coins) {
                    if (c > amount) continue;
                    if (c + num <= amount && !visited[c + num]) {
                        q.offer(c + num);
                    }
                }
            }
            steps++;
        }
        return -1;    
    }
}
