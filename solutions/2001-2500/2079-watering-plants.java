class Solution {
    public int wateringPlants(int[] plants, int capacity) {
        int steps = 0;
        int currCapacity = capacity;
        for (int i = 0; i < plants.length; i++) {
            if (plants[i] > currCapacity) {
                currCapacity = capacity;
                steps += 2*i;
            }
            steps++;
            currCapacity -= plants[i];
        }
        return steps;
    }
}
