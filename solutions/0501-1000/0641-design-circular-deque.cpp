
class MyCircularDeque {
    struct Node {
        Node* next;
        Node* prev;
        int value;
        
        Node (): next(nullptr), prev(nullptr), value(0) {}
        Node(Node* nxt, Node* prv, int val) : next(nxt), prev(prv), value(val) {}
        Node(int val) : next(nullptr), prev(nullptr), value(val) {}
    };
    
public:
    Node* head;
    Node* tail;
    int max_size;
    int size;
    MyCircularDeque(int k) {
        head = nullptr;
        tail = nullptr;
        size = 0;
        max_size = k;
    }
    
    bool insertFront(int value) {
        if (isFull()) return false;
        size++;
        if (head == nullptr) {
            assert(tail == nullptr);
            head = new Node(value);
            tail = head;
        } else {
            Node* node = new Node(value);
            head -> prev = node;
            node -> next = head;
            head = head -> prev;
        }
        return true;
    }
    
    bool insertLast(int value) {
        if (isFull()) return false;
        size++;
        if (tail == nullptr) {
            assert(head == nullptr);
            tail = new Node(value);
            head = tail;
        } else {
            Node* node = new Node(value);
            tail -> next = node;
            node -> prev = tail;
            tail = tail -> next;
        }
        return true;
    }
    
    bool deleteFront() {
        if (isEmpty()) return false;
        size--;
        if (size == 0) {
            head = nullptr;
            tail = nullptr;
            return true; 
        }
        head = head -> next;
        if (head) head -> prev = nullptr;
        return true;
    }
    
    bool deleteLast() {
        if (isEmpty()) return false;
        size--;
        if (size == 0) {
            head = nullptr;
            tail = nullptr;
            return true;
        }
        tail = tail -> prev;
        if (tail) tail -> next = nullptr;
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : head -> value;
    }
    
    int getRear() {
        return isEmpty() ? -1 : tail -> value;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == max_size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
