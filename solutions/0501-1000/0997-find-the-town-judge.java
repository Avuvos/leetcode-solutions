class Solution {
    public int findJudge(int n, int[][] trust) {
        if (n == 1) {
            return 1;
        }
        if (n == 2 && trust.length == 1) {
            return trust[0][1];
        }
        if (n == 2 && trust.length == 2) {
            return -1;
        }
        
        int judge = (n*(n+1))/2;
        Set<Integer> town = new HashSet<>();
        for (int i=0; i<trust.length; i++) {
            town.add(trust[i][0]);
        }
        
        for (int person: town) {
            judge -= person;
        }
        
        if (judge == 0 || town.size() != n-1) {
            return -1;
        }
        boolean [] trustJudge = new boolean[n + 1];
            
        for (int[] person: trust) {
            if (person[1] == judge) {
                trustJudge[person[0]] = true;
            }
        }
        
        for (int i=1; i<trustJudge.length; i++) {
            if (!trustJudge[i] && i != judge) {
                return -1;
            }
        }
        return judge;
    }
}
