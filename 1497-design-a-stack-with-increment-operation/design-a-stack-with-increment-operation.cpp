class CustomStack {
public:
int ans[1000];
int size=0;
int index=-1;
    CustomStack(int maxSize) {
        size=maxSize;
    }
    
    void push(int x) {
        if(index<size-1)
        {
            ans[++index]=x;
        }
    }
    
    int pop() {
        int num=-1;
        if(index>=0)
        {
             num=ans[index];
             ans[index--]=0;
            return num;
        }
        return  num;
    }
    
    void increment(int k, int val) {
        for(int i=0;i<size && i<k;i++)
        {
            ans[i]+=val;
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