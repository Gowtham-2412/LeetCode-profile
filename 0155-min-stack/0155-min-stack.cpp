class MinStack {
private:
    stack<int> main;
    stack<int> minStack;
public:
    MinStack() {
        
    }
    
    void push(int value) {
        main.push(value);
        if(minStack.empty()) {
            minStack.push(value);
        } else {
            minStack.push(min(value, minStack.top()));
        }
    }
    
    void pop() {
        main.pop();
        minStack.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */