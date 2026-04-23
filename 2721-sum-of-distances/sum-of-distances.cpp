// class Solution {
// public:
//     vector<long long> distance(vector<int>& nums) {
//         int size=nums.size();
//         vector<long long > arr(size,0);
//         for(int i=0;i<size;i++)
//         {
//             long long sum=0;
//             for(int j=0;j<size;j++)
//             {
//                 if(nums[i]==nums[j] && i!=j)
//                 {
//                       sum=sum +abs(i-j);
//                 }
//             } 
//         arr[i]=sum;
//         }
//         return arr;
//     }
// };


class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int size=nums.size();
        
        vector<long long > ans(size,0);
        unordered_map<int,vector<int>>group;
        for(int i=0;i<size;i++)
        {
            group[nums[i]].push_back(i);
        }

        for(auto & entry:group)
        {
            vector<int>&pos=entry.second;
            int k=pos.size();
            if(k==1)
            {
                ans[pos[0]]=0;
                continue;
            }
        

        long long firstsum=0;
        for(int i=0;i<k;i++)
        {
            firstsum += (long long )(pos[i]-pos[0]);
        }

        ans[pos[0]]=firstsum;

        for(int i=1;i<k;i++)
        {
            long long gap=pos[i]-pos[i-1];
            long long leftcount=i;
            long long rightcount=k-i;
            ans[pos[i]]= ans[pos[i-1]]+leftcount*gap- rightcount* gap;
        }
        }
        return ans;
    }
};