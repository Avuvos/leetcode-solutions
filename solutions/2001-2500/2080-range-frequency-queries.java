class RangeFreqQuery {
        int[] arr;
        HashMap<Integer, TreeMap<Integer, Integer>> map;
        public RangeFreqQuery(int[] arr) {
            this.arr = arr;
            this.map = new HashMap<>();
            fillMap();
        }
        public void fillMap(){
            for (int i = 0; i < arr.length; i++) {
                if (!map.containsKey(arr[i])) {
                    map.put(arr[i], new TreeMap<>());
                }
                map.get(arr[i]).put(i, map.get(arr[i]).size());
            }
        }
        public int query(int left, int right, int value) {
            if (!map.containsKey(value)) return 0;
            TreeMap<Integer, Integer> indices = map.get(value);
            Integer leftBound = indices.ceilingKey(left);
            Integer rightBound = indices.floorKey(right);
            if (leftBound == null || rightBound == null) return 0;
            return indices.get(rightBound) - indices.get(leftBound) + 1;
        }
}

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery obj = new RangeFreqQuery(arr);
 * int param_1 = obj.query(left,right,value);
 */
