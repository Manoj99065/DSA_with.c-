class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
       int size=nums.size();
       unordered_map<int,int>ans;
       vector<int>ans1;

       int mx=nums[0];
       int mn=nums[0];


       // here we are store the element int the map;
       for(int i=0;i<nums.size();i++)
       {
         ans[nums[i]]=1;

         mx=max(mx,nums[i]);
         mn=min(mn,nums[i]);
       }


       // here we are find the element oky and put in the ans.

       for(int i=mn;i<mx;i++)
       { 
          if(ans.find(i)==ans.end())
          {
            ans1.push_back(i);
          }
       }
       return ans1;
    }
};






















// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         int size=nums.size();
//         sort(nums.begin(),nums.end());
//         int curr=nums[0];
//         vector<int>ans;
//         for(int i=0;i<size;i++)
//         {
//             while(curr<nums[i])
//             {
//               ans.push_back(curr);
//               curr++;
//             }

//             curr++;
//         }
//         return ans;
        
//     }