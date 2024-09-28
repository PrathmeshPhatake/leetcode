class MyCircularDeque {
public:
deque<int>ans;
int size=0;
    MyCircularDeque(int k) {
        
        size=k;
    }
    
    bool insertFront(int value) {
       
        if(ans.size()<size)
        {
            ans.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(ans.size()<size)
        {
            ans.push_back(value);
            return true;

        }
        return false;
    }
    
    bool deleteFront() {
        if(!ans.empty())
        {
         ans.pop_front();
         return true;           
        }
        return false;

    }
    
    bool deleteLast() {
        if(!ans.empty())
        {
         ans.pop_back();
         return true;           
        }
        return false;
    }
    
    int getFront() {
        if(!ans.empty())
        {return ans.front();}
        return -1;
    }
    
    int getRear() {
        if(!ans.empty())
        {return ans.back();}
        return -1;
    }
    
    bool isEmpty() {
       return ans.empty();
    }
    
    bool isFull() {
        return ans.size()==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */