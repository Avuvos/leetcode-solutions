class EventManager {
public:
    unordered_map<int, int> id_to_pr;
    set<pair<int, int>> ordered_events; // (-prio, id)
    EventManager(vector<vector<int>>& events) {
        id_to_pr.clear();
        ordered_events.clear();
        for (auto &e: events) {
            updatePriority(e[0], e[1]);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int prio = id_to_pr[eventId];
        ordered_events.erase({-prio, eventId});
        ordered_events.insert({-newPriority, eventId});
        id_to_pr[eventId] = newPriority;
    }
    
    int pollHighest() {
        if (ordered_events.empty()) {
            return -1;
        }
        auto it = ordered_events.begin();
        int ans = it -> second;
        ordered_events.erase(it);
        id_to_pr.erase(ans);
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
