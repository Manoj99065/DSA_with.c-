class RecentCounter {
public:
int count;
int store;
queue<int>qu;
    RecentCounter() {
        // count=0; 
        // store=INT_MIN;
    }
    
    int ping(int t) {

            while(!qu.empty() &&  qu.front()<t-3000)
            {
                qu.pop();
            }
           qu.push(t);
        
        return qu.size();    
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */