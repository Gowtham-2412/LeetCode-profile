class MyQueue {
public:
    stack<int> inputSt;
    stack<int> outputSt;
    MyQueue() {
    }
    
    void push(int x) {
        inputSt.push(x);
    }
    
    int pop() {
        int val = peek();
        outputSt.pop();
        return val;
    }
    
    int peek() {
        if(outputSt.empty()) {
            while(!inputSt.empty()) {
                outputSt.push(inputSt.top());
                inputSt.pop();
            }
        }
        return outputSt.top();
    }
    
    bool empty() {
        return inputSt.empty() && outputSt.empty();
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