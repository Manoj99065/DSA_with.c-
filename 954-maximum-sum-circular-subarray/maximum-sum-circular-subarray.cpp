class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(2*n);
        for(int i=0;i<2*n;i++)
        {
            arr[i]=nums[i % n];
        }
        vector<int>prefix(2*n+1,0);
        for(int i=0;i<2*n;i++)
        {
           prefix[i+1]=prefix[i]+arr[i] ;
        }


        // here we are implement the concept of the deque and another like max_sum
        int ans=INT_MIN;
        deque<int>qu;

        for (int j = 0; j <= 2*n; j++)
        {
            while(!qu.empty() && qu.front() < j-n)
            {
                qu.pop_front();
            }
            if(!qu.empty())
            {
                ans=max(ans,prefix[j]-prefix[qu.front()]);
            }
            while(!qu.empty() && prefix[qu.back()] >= prefix[j])
            {
                qu.pop_back();
            }
        qu.push_back(j);
        }
        return ans;
    }
};