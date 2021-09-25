class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int []> res = new ArrayList<>();
        int start = newInterval[0];
        int end = newInterval[1];
        int i = 0;
        
        //3 stages, pre overlap, overlap, and after overlap
        //pre and after is easy cuz we just add them to the result
        //in the overlap case, we take the min between start and the next start
        //and take the max between the end and next end
        
        while (i < intervals.length && intervals[i][1] < start) { //pre overlap
            res.add(intervals[i]);
            i++;
        }
        while (i<intervals.length && (end >= intervals[i][0])) { //overlap
            start = Math.min(intervals[i][0], start);
            end = Math.max(intervals[i][1], end);
            i++;
        }
        res.add(new int[] {start, end});
        
        while (i < intervals.length) { //after overlap
            res.add(intervals[i]);
            i++;
        }
        return res.toArray(new int[0][]);
    }
}
