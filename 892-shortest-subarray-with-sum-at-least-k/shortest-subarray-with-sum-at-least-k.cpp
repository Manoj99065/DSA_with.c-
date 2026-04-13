// class Solution {
// public:
//     int shortestSubarray(vector<int>& nums, int k) {
//         queue<int>qu;
//         int sum=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             sum=sum+nums[i];
//             qu.push(i);
            
//             if(k==nums[i])
//             {
//                 return 1;
//             }
//             else if(!qu.empty())
//             {
                
//                 while(sum>k)
//                 {
//                     int val=qu.front();
//                     // cout<<qu.size();
//                     qu.pop();
//                     // cout<<qu.front();
//                     sum=sum-nums[val];
//                     // cout<<qu.size();
//                     if(sum==k) return qu.size();    
//                 }
//                 // cout<<qu.size();
//                 if(sum==k) return qu.size();     
                   
//             }
           
//         }
//       return -1;    
//     }
// };


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }

        // here we are apply the concept of deque and another one like .
        deque<int>dq;
        int ans=INT_MAX;
        for(int i=0;i<=n;i++)
        {
            while(!dq.empty() && (prefix[i] - prefix[dq.front()] >= k)) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
        

            // maintain the increasing orderd.
            while(!dq.empty() && prefix[i]<=prefix[dq.back()])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans==INT_MAX ? -1:ans;
    }
};