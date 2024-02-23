class MyQueue {
private:
    stack<int> sin, sout;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        sin.push(x);
    }
    
    int pop() {
        if(sout.empty()){
            while(!sin.empty()){
                sout.push(sin.top());
                sin.pop();
            }
        }
        int temp = sout.top();
        sout.pop();
        return temp;
    }
    
    int peek() {
        if(sout.empty()){
            while(!sin.empty()){
                sout.push(sin.top());
                sin.pop();
            }
        }
        int temp = sout.top();
        return temp;
    }
    
    bool empty() {
        return sin.empty() && sout.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */