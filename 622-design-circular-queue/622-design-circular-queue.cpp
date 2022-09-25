class MyCircularQueue {
private:
    vector<int> q;
    int f, r, sz;
public:
    MyCircularQueue(int k) {
        q.resize(k, -1);
        f = 0;
        r = 0;
        sz = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        q[r] = value;
        r = (r + 1) % sz;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        q[f] = -1;
        f = (f + 1) % sz;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return q[f];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return q[(r + sz - 1) % sz];
    }
    
    bool isEmpty() {
        return f == r and q[f] == -1;
    }
    
    bool isFull() {
        return f == r and q[f] != -1;
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