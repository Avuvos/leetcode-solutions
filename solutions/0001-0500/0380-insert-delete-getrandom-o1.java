class RandomizedSet {
     HashMap<Integer, Integer> map;
        List<Integer> lst;
        public RandomizedSet() {
            map = new HashMap<Integer, Integer>();
            lst = new ArrayList<>();
        }
        public boolean insert(int val) {
            if (map.containsKey(val)) return false;
            int s = lst.size();
            map.put(val, s);
            lst.add(val);
            return true;
        }

        public boolean remove(int val) {
            if (!map.containsKey(val)) return false;
            int ind = map.get(val);
            if (ind < lst.size() - 1) {
                int LastNum = lst.get(lst.size() - 1);
                lst.set(ind, LastNum);
                map.put(LastNum, ind);
            }
            lst.remove(lst.size() - 1);
            map.remove(val);
            return true;
        }
        public int getRandom() {
            Random random = new Random();
            int ind = random.nextInt(lst.size());
            return lst.get(ind);
        }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
