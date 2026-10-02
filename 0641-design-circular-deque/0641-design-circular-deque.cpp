class MyCircularDeque {
    private:
        vector<int> arr;
        int front;
        int rear;
        int size; //occupied size
        int capacity; //maximum size
    public:
        MyCircularDeque(int k) {
            arr.resize(k);
            capacity = k;
            front = 0;
            rear = -1;
            size = 0;
        }
    
        bool insertFront(int value) {
            if(size >= capacity){
                return false;
            }
            if(size == 0){
                front = 0;
                rear = 0;
            }
            else{
                front = (front - 1 + capacity) % capacity;
            }
            size++;
            arr[front] = value;
            return true;
        }
    
        bool insertLast(int value) {
            if(size >= capacity){
                return false;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = value;
            size++;
            return true;
        }
    
        bool deleteFront() {
            if(size == 0){
                return false;
            }
            front = (front + 1 ) % capacity;
            size--;
            return true;
        }
    
        bool deleteLast() {
            if(size == 0){
                return false;
            }
            rear = (rear - 1 + capacity) % capacity;
            size--;
            return true;
        }
    
        int getFront() {
            if(size == 0){
                return -1;
            }
            return arr[front];
        }
    
        int getRear() {
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
            return size == capacity;
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