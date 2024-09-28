class FrontMiddleBackQueue {
public:
    deque<int>dq1,dq2; // initialisation
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) 
    {
        dq1.push_front(val);
        balance(); // we have to try  equal elements in both deque
    }
    
    void pushMiddle(int val) 
    {
        if((dq1.size()+dq2.size())%2==0) // if both deque have equal size
        {
            dq1.push_back(val);
        }
        else  
        {   // we deleting last element to dq1 and pushing deleting element to dq2.
            // then push given value to back to dq1
            int x = dq1.back();
            dq1.pop_back();
            dq1.push_back(val);
            dq2.push_front(x);
        }
    }
    
    void pushBack(int val) 
    {
        dq2.push_back(val);
        balance(); // we have to try  equal elements in both deque
    }
    
    int popFront() 
    {
        if(dq1.empty()) // if data structure contain no elements
        return -1;
        int x = dq1.front(); 
        dq1.pop_front();
        balance();
        return x;
    }
    
    int popMiddle() 
    {
        if(dq1.empty())  // if data structure contain no elements
        return -1;
        int x = dq1.back();
        dq1.pop_back();
        balance();
        return x;
    }
    
    int popBack() 
    {
        if(dq2.empty())  // if q2 is empty then dq1 can be empty or not
        {
            if(dq1.empty())
            return -1;
            else
            {
                int x = dq1.back();
                dq1.pop_back();
                return x;
            }
        }

        int x = dq2.back();
        dq2.pop_back();
        balance();
        return x;
    }
    void balance()
    {
        // if size(dq1) - size(dq2)==1 or ==0, we do nothing
        if(dq1.size()==dq2.size() || dq1.size()-dq2.size()==1)
            return;   
        if(dq1.size()>dq2.size()) // if size(dq1) - size(dq2) > 1
        {
            int x = dq1.back();
            dq1.pop_back();
            dq2.push_front(x);
        }
        else
        {    // if size(dq2) > size(dq1)
            int x = dq2.front();
            dq2.pop_front();
            dq1.push_back(x);
        }
    }
};