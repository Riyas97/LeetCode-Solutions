class MinStack {
public:
    
    stack <int> st;
    map <int, int> m;
    
    MinStack() {    
    }
    
    void push(int val) {
        st.push(val);
        m[val]++;
    }
    
    void pop() {
        int val = st.top();
        st.pop();
        if (m[val] == 1) {
            m.erase(val);
        } else {
            m[val]--;    
        }
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        auto it = m.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */