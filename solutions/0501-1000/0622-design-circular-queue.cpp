class MyCircularQueue {
public:
    int size;
    queue<int> q;
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if (q.size() == size) return false;
        q.push(value);
        return true;
    }
    
    bool deQueue() {
        if (q.empty()) return false;
        q.pop();
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q.front();
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size() == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
