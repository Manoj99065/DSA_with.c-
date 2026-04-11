// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         if(nums.size()<k)
//         {
//             return {};
//         }
//         // queue<int>qe;
//         int front=0;
//         int rear=k-1;
//         vector<int>arr;
        
//         for(int i=k-1;i<nums.size();i++)
//         {
//             int MIN=INT_MIN;
//             for(int j=front;j<=rear;j++)
//             {
//                 if(nums[j]>MIN)
//                 {
//                     MIN=nums[j];
//                 }
//             }
//             arr.push_back(MIN);
//             front++;
//             rear++;
//         }   
//     return arr;
//     }
// };

class Solution {
public:
    deque<int>qu;
    vector<int>ans;
    int maxi=0;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++)
        {
            if(!qu.empty() && qu.front()==i-k)
            {
                qu.pop_front();
            }


            while(!qu.empty() && nums[qu.back()]<nums[i])
            {
                qu.pop_back();
            }

            qu.push_back(i);
            if(i>=k-1)
            {
                ans.push_back(nums[qu.front()]);
            }
        }
        return ans;
        }
};