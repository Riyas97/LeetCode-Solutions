class MyQueue {
public:
    stack <int> s1;
    stack <int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while (!s1.empty()) {
            int num = s1.top();
            s2.push(num);
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            int num = s2.top();
            s1.push(num);
            s2.pop();
        }
    }
    
    int pop() {
        int num = s1.top();
        s1.pop();
        return num;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        if (s1.empty()) {
            return true;
        }
        return false;
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