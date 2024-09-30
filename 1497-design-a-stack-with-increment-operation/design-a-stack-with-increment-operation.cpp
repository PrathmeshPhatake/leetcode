class CustomStack {
public:
stack<int>st1;
stack<int>st2;
int size=0;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(st1.size()<size)
        {
            st1.push(x);
        }
        
    }
    
    int pop() {
        if(!st1.empty())
        {
            int num=st1.top();
            st1.pop();
           return num;
        }
        return -1;
        
    }
    
    void increment(int k, int val) {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        while(!st2.empty())
        {
            int num=st2.top();
            st2.pop();
            if(k>0)
            {
                num=num+val;
                st1.push(num);
                k--;
            }
            else
            {
                st1.push(num);
            }
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