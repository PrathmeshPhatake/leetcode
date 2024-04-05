class MinStack {
public:
    stack<pair<int,int>>sq;
    MinStack() {
        
    }
    
    void push(int val) {
        
       if(sq.empty())
       {
        sq.push({val,val});
       }
       else
       {
        int min_for_sec=min(val,sq.top().second);
        sq.push({val,min_for_sec});
       }
    }
    
    void pop() {
 
        sq.pop();
        
        
    }
    
    int top() {
        return sq.top().first;
    }
    
    int getMin() {
        return sq.top().second;
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