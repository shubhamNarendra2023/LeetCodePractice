class MyStack {
    private:
    queue<int> q1,q2;
    int size;
public:
    MyStack() {
        size = q2.size();
    }
    
    void push(int x) {
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1,q2);
    }
    
    int pop() {
        if(!q2.empty()){
            int ans = q2.front();
            q2.pop();
            return ans;
        }
        else{
            return -1;
        }        
    }
    
    int top() {
        if(!q2.empty()){
            return q2.front();
        }
        else{
            return -1;
        }
    }
    
    bool empty() {
        if(q2.empty()){
            return 1;
        }
        else{
            return 0;
        }
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