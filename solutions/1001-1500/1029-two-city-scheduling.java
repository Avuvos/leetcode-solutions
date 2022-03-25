class Solution {
    class Person implements Comparable<Person>{
        private int idx;
        private int costA;
        private int costB;
        private int prefCity;
        private int gap;
        
        public Person(int idx, int costA, int costB) {
            this.idx = idx;
            this.costA = costA;
            this.costB = costB;
            this.prefCity = Math.min(costA, costB);
            this.gap = Math.abs(costA - costB);
        }
        
        //sort the gaps from big to low
        public int compareTo(Person o) {
            return Integer.compare(o.gap, this.gap);
        }
        
    }
    
    public int twoCitySchedCost(int[][] costs) {
        PriorityQueue<Person> pq = new PriorityQueue<>();
        for (int i = 0; i < costs.length; i++) {
            pq.offer(new Person(i, costs[i][0], costs[i][1]));
        }
        
        
        int res = 0, n = costs.length / 2;
        int a = 0, b = 0;
        
        //apply greedy algorithm
        while (!pq.isEmpty()) {
            Person p = pq.poll();
            if (b < n) {
                if (p.prefCity == p.costB || a == n) {
                    b++;
                    res += p.costB; 
                }
                else {
                    a++;
                    res += p.costA;
                }
            }
            else {
                a++;
                res += p.costA;
            }
        }
        return res;
    }
}
