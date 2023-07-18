class LRUCache {
public:
    unordered_map<int, int> cache;
    unordered_map<int, int> key_to_time;
    set<pair<int, int>> s; //(time, key) pairs
    int t = 0;
    int capacity;
    LRUCache(int capacity) {
        t = 0;
        s.clear();
        cache.clear();
        this -> capacity = capacity;
    }
    
    void balance() {
        if (cache.size() <= capacity) return;
        auto [time, key_val] = *s.begin();
        s.erase(s.begin());
        key_to_time.erase(key_val);
        cache.erase(key_val);
    }
    
    void update(int key) {
        s.erase(make_pair(key_to_time[key], key));
        s.insert(make_pair(t, key));
        key_to_time[key] = t;
        t++;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        update(key);
        return cache[key];
    }
    
    void put(int key, int value) {
        update(key);
        cache[key] = value;
        balance();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
