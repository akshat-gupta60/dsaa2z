class MinStack {
public:
    
    stack<long long int>st;
    long long int mn=1e8;
    
    MinStack() {
        
    }
    
    void push(int val) {

        if(st.size()==0){
            st.push(val);
            mn=val;
        }
       else{
            if(val<mn){

                st.push(2*1ll*val-mn);
                mn=val;
            }
            else{
                st.push(val);
            }
       }
    }
    
    void pop() {
        if(st.top()<mn){
            mn=(2*mn)-st.top();
            st.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<mn) return mn;
        return st.top();
    }
    
    int getMin() {
        return mn;
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