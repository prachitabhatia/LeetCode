class MyStack {
    queue<int> q;
public:
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);        
    }
    
    int pop() {
        int rotations = q.size() - 1;
        for(int i = 0; i < rotations; i++){
            q.push(q.front());
            q.pop();
        }
        int deleted = q.front();
        q.pop();
        return deleted;
    }
    
    int top() {
        int rotations = q.size() - 1;
        for(int i = 0; i < rotations; i++){
            q.push(q.front());
            q.pop();
        }
        int top = q.front();
        q.push(q.front()); //making the queue back to original after rotating the last element
        q.pop();
        return top;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */