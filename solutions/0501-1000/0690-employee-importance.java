/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        int total = 0;
        Queue<Employee> q = new LinkedList<>();
        Map<Integer, Employee> map = new HashMap<Integer, Employee>();
        for (Employee emp: employees) {
            map.put(emp.id, emp);
        }
        q.offer(map.get(id));
        
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                Employee emp = q.poll();
                assert emp != null;
                total += emp.importance;
                for (Integer sub: emp.subordinates) {
                    q.offer(map.get(sub));
                }
            }
        }
        return total;
    }
}
