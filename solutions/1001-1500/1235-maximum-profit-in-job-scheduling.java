class Solution {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int[][] jobs = new int[startTime.length][3]; //create jobs array and sort it
        for (int i = 0; i < startTime.length; i++) { //by starting time
            jobs[i] = new int[]{startTime[i], endTime[i], profit[i]};
        }
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        
        return dfs(jobs, 0);
    }
    
    public int dfs(int[][] jobs, int i) {
        
        if (i >= jobs.length)
            return 0;
        if (map.containsKey(i)) //using memoization
            return map.get(i);
        
        int index = getIndex(jobs, i); //we can either take the job or skip it
        int take = jobs[i][2] + dfs(jobs, index); 
        int skip = dfs(jobs, i+1);
        
        map.put(i, Math.max(take, skip)); //return the max profit
        return map.get(i);
       
    }
    
    public int getIndex(int[][] jobs, int ind) { //gets the next possible job 
        int n = jobs.length;
        int e = jobs[ind][1];
        for (int i=ind+1; i<n; i++) {
            if (jobs[i][0] >= e) {
                return i;
            }
        }
        return n+1; //so we can break out of the loop
    }
}
