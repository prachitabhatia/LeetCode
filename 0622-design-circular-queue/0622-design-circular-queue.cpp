class MyCircularQueue {
    private:
        vector<int> arr; //dynamic array
        int front;
        int rear;
        int size; //occupied size
        int capacity; //maximum size
    
    public:
            // constructor
            MyCircularQueue(int k) {
                capacity = k;
                arr.resize(k);
                front = 0;
                rear = -1;
                size = 0;
            }
    
            bool enQueue(int value) {
                if(size >= capacity){
                    return false;
                }
                size++;
                rear = (rear + 1) % capacity;
                arr[rear] = value;
                return true;
            }
    
            bool deQueue() {
                if(size == 0){
                    return false;
                }
                front = (front + 1) % capacity;
                size--;
                return true;
            }
    
            int Front() {
                if(size == 0){
                    return -1;
                }
                return arr[front];
            }
    
            int Rear() {
                if(size == 0){
                    return -1;
                }
                return arr[rear];
            }
    
            bool isEmpty() {
                if(size == 0){
                    return true;
                }
                return false;
            }
    
            bool isFull() {
                if(size == capacity){
                    return true;
                }
                return false;
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