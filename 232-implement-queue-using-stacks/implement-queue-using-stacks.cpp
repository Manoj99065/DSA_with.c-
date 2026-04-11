class MyQueue {
public: 
    stack<int>st1;
    stack<int>st2;
    int peak1;
    int count=0;
    MyQueue() {
        // int size=100001;
        // arr=new int [size];
        // top=0;
        // peak1=0;
    }
    
    void push(int x) {
        st1.push(x);
        if(count==0)
        {
        // peak1=x;
        count++;
        }    
    }
    
    int pop() {
        if(st2.empty())
        {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        }
        if(st2.empty())return -1;
        int element=st2.top();
        
        st2.pop();
        // if(!st2.empty()) peak1=st2.top();
        return element;
        
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }

        if (st2.empty()) return -1; // queue is empty
        return st2.top();  
        return peak1;  
    }
    
    bool empty() {
        if(st2.empty() && st1.empty())
        {
            return true;
        }
        return false;
        
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