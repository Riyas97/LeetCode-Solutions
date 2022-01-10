class CustomStack {
public:
    vector<int> vect;
    int s = 0;
    
    CustomStack(int maxSize) {
        s = maxSize;    
    }
    
    void push(int x) {
        if (vect.size() < s) {
            vect.push_back(x);
        }
    }
    
    int pop() {
        if (vect.size() == 0) {
            return -1;
        }
        int num = vect[vect.size() - 1];
        vect.pop_back();
        return num;
    }
    
    void increment(int k, int val) {
        for (int i = 0; i < k; i++) {
            if (i == vect.size()) {
                break;
            }
            vect[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */