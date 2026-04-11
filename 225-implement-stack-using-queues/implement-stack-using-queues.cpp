// class MyStack {
// public:
//     int *arr;
//     int m;
//     int size;
//     int front;
//     int rear;
//     MyStack() {
//         m=100001;
//         arr=new int [m];
//         size=0;
//         rear=0;
//         front=-1;

        
//     }
    
//     void push(int x) {
//         arr[rear]=x;
//         rear++;
//         // size++;    
//     }
    
//     int pop() {
//         if(rear==0)
//         {
//             return -1;
//         }
        
//         int element=arr[rear-1];
//         rear=rear-1;
//         // delete arr[front];
//         // size=size-1;
//         return element;

        
//     }
    
//     int top() {
//         if(rear==0)
//         {
//             return -1;
//         }
//         else
//         {
//             return arr[rear-1];
//         }
        
//     }
    
//     bool empty() {
//         if(rear==0)
//         {
//             return true;
//         }
//         return false;
        
//     }
// };

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


 class MyStack {
public:
  deque<int>qu;
    MyStack() {  
    }
    
    void push(int x) {
       qu.push_back(x);
        // size++;    
    }
    
    int pop() {
        int l=qu.back();
        qu.pop_back();
        return l;

       
    }
    
    int top() {
       
      return qu.back();  
    }
    
    bool empty() {
      return qu.empty() ? true : false;
        }
};