class MinStack {
public:
    /** initialize your data structure here. */
    stack<int>actual;
    stack<int>mnStack;
    MinStack() {
       // actual.clear();
        //mnStack.clear();
    }
    
    void push(int x) {
        actual.push(x);
        if(!mnStack.empty()){
            mnStack.push(min(mnStack.top(),x));
        }
        else{
            mnStack.push(x);
        }
    }
    
    void pop() {
        actual.pop();
        mnStack.pop();
    }
    
    int top() {
        return actual.top();
    }
    
    int getMin() {
        return mnStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */