class Solution {
    Map<Integer, Integer> map = new HashMap<Integer, Integer>();
    
    public int mincostTickets(int[] days, int[] costs) {
        return dfs(days, costs, days[0]-1);
    }
    
    public int dfs(int[] days, int[] costs, int currDay) {
        if (currDay > days[days.length-1]) {
            return 0;
        }
        if (map.containsKey(currDay)) {
            return map.get(currDay);
        }
        int oneDay = costs[0] + dfs(days, costs, findNextDay(days, currDay+1));
        int sevenDays = costs[1] + dfs(days, costs, findNextDay(days, currDay+7));
        int thirtyDays = costs[2] + dfs(days, costs, findNextDay(days, currDay+30));
        
        int res = Math.min(Math.min(oneDay, sevenDays), thirtyDays);
        map.put(currDay, res);
        return res;
        
    }
    
    public int findNextDay(int[] days, int currDay) {
        if (currDay > days[days.length-1]) return 366;
        for (int i=0; i<days.length; i++) {
            if (days[i] > currDay) {
                return days[i]-1;
            }
        }
        return 366;
    }
}
