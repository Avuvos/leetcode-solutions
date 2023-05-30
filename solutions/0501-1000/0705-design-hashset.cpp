class MyHashSet {
public:
    const int N = 1e6+1;
    vector<int> arr;
    MyHashSet() {
        arr = vector<int>(N, 0);
    }
    
    void add(int key) {
        arr[key] = 1;
    }
    
    void remove(int key) {
        arr[key] = max(0, arr[key] - 1);
    }
    
    bool contains(int key) {
        return arr[key] > 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
