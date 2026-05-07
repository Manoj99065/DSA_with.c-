// class Solution {
// public:
//     vector<int> maxValue(vector<int>& nums) {
//         vector<int>ans;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=0;j<nums.size();j++)
//             {
//                 if(j>=i)
//                 {
//                     if(nums[j]<nums[i])
//                     {
//                         ans.push_back(nums[i]);
//                         break;
//                     }
//                 }
//                 if(j<=i)
//                 {
//                     if(nums[j]>=nums[i])
//                     {
//                         ans.push_back(nums[j]);
//                         break;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        if (nums.empty()) return {};
        int n=nums.size();
        vector<int>ans(n);
        vector<int>prefix(n,INT_MIN);
        vector<int>suffix(n,INT_MAX);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = max(prefix[i-1], nums[i]);
            // prefix[i]=nums[i];
        }
        suffix[n-1]=nums[n-1];

        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],nums[i]);
        }

        //  this loop is apply to get the answer.
        ans[n-1]=prefix[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(prefix[i]<=suffix[i+1])
            {
                ans[i]=prefix[i];
            }
            else
            {
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};
