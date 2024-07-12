class MinStack {
public:
    stack<pair<int,int>>st;
    stack<int>st1;
    
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()) st.push({val,val});
        else {
            int mn=min(st.top().second,val);
            st.push({val,mn});
        }
        st1.push(val);
    }
    
    void pop() {
        st.pop();
        st1.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your st1 object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */