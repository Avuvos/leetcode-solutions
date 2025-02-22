class TaskManager {
public:
    unordered_map<int, pair<int, int>> mp;  // task_id -> (priority, user_id)
    set<pair<int, int>> s; // (-priority, -task_id)
    TaskManager(vector<vector<int>>& tasks) {
        mp.clear();
        s.clear();
        for (auto &task: tasks) {
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        s.insert({-priority, -taskId});
        mp[taskId] = {priority, userId};
    }
    
    void edit(int taskId, int newPriority) {
        auto [p, uid] = mp[taskId]; 
        s.erase({-p, -taskId});
        s.insert({-newPriority, -taskId});
        mp[taskId] = {newPriority, uid};
    }
    
    void rmv(int taskId) {
        auto [p, _] = mp[taskId];
        s.erase({-p, -taskId});
        mp.erase(taskId);
    }
    
    int execTop() {
        if (s.empty()) return -1;
        auto [_, tid] = *s.begin();
        tid *= -1;
        auto [_, uid] = mp[tid];
        rmv(tid);
        return uid;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
