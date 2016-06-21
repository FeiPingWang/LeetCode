class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if(min.empty())
            min.push(x);
        else
        {
            if(min.top() >= x)
                min.push(x);
        }
        s1.push(x);
    }
    
    void pop() {
        if(min.top() == s1.top())
            min.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
       // if(!min.empty())
            return min.top();
    }
private:
    stack<int> s1;
    stack<int> min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
