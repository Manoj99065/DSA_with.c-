// /**
//  * // This is the interface that allows for creating nested lists.
//  * // You should not implement it, or speculate about its implementation
//  * class NestedInteger {
//  *   public:
//  *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
//  *     bool isInteger() const;
//  *
//  *     // Return the single integer that this NestedInteger holds, if it holds a single integer
//  *     // The result is undefined if this NestedInteger holds a nested list
//  *     int getInteger() const;
//  *
//  *     // Return the nested list that this NestedInteger holds, if it holds a nested list
//  *     // The result is undefined if this NestedInteger holds a single integer
//  *     const vector<NestedInteger> &getList() const;
//  * };
//  */

// class NestedIterator {
// public:
//     int i=0;
//     vector<int>ans;
//     void nestlist(vector<NestedInteger>&nestedList){
//     for(int i=0;i<nestedList.size();i++)
//     {
//         if(nestedList[i].isInteger())
//         {
//            ans.push_back(nestedList[i].getInteger());
//         }
//         else
//         {
//            nestlist(nestedList[i].getList());
//         }
//     }
//     }
//     NestedIterator(vector<NestedInteger> &nestedList) {
//      nestlist(nestedList);    
//     }
    
//     int next() {
//         int I=-1;
//         if(i<ans.size())
//         {
//             I=ans[i];
//             i++;
//         }
//         // int ans=ans.at(i);
//         // i++;
//         return I;
        
//     }
    
//     bool hasNext() {
//         if(i<ans.size())
//         {
//             return true;
//         }
//         else
//         {
//             return false;
//         }    
//     }
// };

// /**
//  * Your NestedIterator object will be instantiated and called as such:
//  * NestedIterator i(nestedList);
//  * while (i.hasNext()) cout << i.next();
//  */



class NestedIterator {
public:
    int i=0;
    vector<int>ans;
    int index=0;
    void nestlist(vector<NestedInteger>&nestedList){
      for(auto & i:nestedList)
      {
        if(i.isInteger())
        {
            ans.push_back(i.getInteger());
        }
        else
        {
            nestlist(i.getList());
        }
      }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
     nestlist(nestedList);    
    }
    
    int next() {
        // int ans=ans.at(i);
        // i++;
        return ans[index++];
        
    }
    
    bool hasNext() {
        return ans.size()>index;  
    }
};
