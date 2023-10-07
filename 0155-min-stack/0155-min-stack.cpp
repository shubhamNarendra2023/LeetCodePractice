class MinStack {
public:
    stack<int>s;
    multiset<int>m;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        m.insert(val);
    }
    
    void pop() {
        int top = s.top();
        s.pop();
        m.erase(m.find(top));
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return *m.begin();
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