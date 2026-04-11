// class Solution {
// public:
//     int minimumDistance(vector<int>& nums) {
//         int sum=INT_MAX;
//         int count=0;
//         for(int i=0;i<nums.size();i++)
//         {
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 for(int k=j+1;k<nums.size();k++)
//                 {
//                     if(nums[i]==nums[j] && nums[j]==nums[k] && nums[k]==nums[i])
//                     {
//                         // int k = 2*(max(i,max(j,k) - min(i,min(j,k))));
//                         int M = 2 * (max(i,max(j,k))  - min(i,min(j,k)));
//                         cout<<M;
//                         if(M<sum)
//                         {
//                             count=1;
//                             sum=M;
//                         }
//                     }
//                 }
//             }
//         }
//         if(nums.size()<3 || count==0)
//         {
//             return -1;
//         }
//         return sum;
//     }
// };



// class Solution {
// public:
//     int minimumDistance(vector<int>& nums) {
        
//         int size=nums.size();
//         if(size<3 )
//         {
//             return -1;
//         }
//         int sum=INT_MAX;
//         unordered_map<int,int>mp;
//         for(int i=0;i<size;i++)
//         {
//             mp[nums[i]]++;
//         }
//         vector<int>ans;
//         int maxfreq=3;
//         for(auto it:mp)
//         {
//            if(it.second>=maxfreq)
//            {
//             // maxfreq=it.second;
//             // ans.clear();
//             ans.push_back(it.first);
//            }
//         //    else if(it.second==maxfreq)
//         //    {
//         //     ans.push_back(it.first);
//         //    }
//         }
//         int l=0;
//         int x,y,z;
        
//         for(int a:ans)
//         {
//             int count=0;
//             vector<int>res;
//             for(int i=0;i<nums.size();i++)
//             {
//                 if(a==nums[i])
//                 {
//                     res.push_back(i);
//                 }
//                 // if(a==nums[i] && count==0)
//                 // {
//                 //   x=i;
//                 //   count++;
//                 // }
//                 // else if(a==nums[i] && count==1)
//                 // {
//                 //     y=i;
//                 //     count++;
//                 // }
//                 // else if(a==nums[i] && count==2)
//                 // {
//                 //    z=i;
//                 //    l=1;
//             }
//                 for(int i=0;i+2<res.size();i++)
//                 {
//                     int x=res[i];
//                     int y=res[i+1];
//                     int z=res[i+2];
//                     int R=2*(z-x);
//                     sum=min(sum,result);
//                 }
//         }
//             // int result=2*(max(x,max(y,z)) - min(x,min(y,z)));
//             // if(result<sum)
//             // {
//             //     sum=result;
//             // }
//         }
//         // if(l!=1)
//         // {
//         //     return -1;
//         // }
//         return sum;
//     }
// };



// class Solution {
// public:
//     int minimumDistance(vector<int>& nums) {
        
//         int size=nums.size();
//         if(size<3 )
//         {
//             return -1;
//         }
//         int sum=INT_MAX;
//         unordered_map<int,int>mp;
//         for(int i=0;i<size;i++)
//         {
//             mp[nums[i]]++;
//         }
//         vector<int>ans;
//         // int maxfreq=3;
//         bool ans1=false;
//         int maxfreq = 0;

//         for(auto it: mp){
//             maxfreq = max(maxfreq, it.second);
//         }



//         for(auto it:mp)
//         {
//            if(it.second==maxfreq)
//            {
//             ans.push_back(it.first);
//             ans1=true;
//            }    
//         }

//         bool ok=false;
//         // int ANS=INT_MAX; 
//         for(int a:ans)
//         {
//             int count=0;
//             vector<int>res;
//             for(int i=0;i<nums.size();i++){
//                 if(a==nums[i]){
//                     res.push_back(i);}
//                 }

//             for(int i=0;i+2<res.size();i++)
//             { 
//                     ok=true;
//                     int x=res[i];
//                     int y=res[i+1];
//                     int z=res[i+2];
//                     int R=2*(z-x);
//                     sum=min(sum,R);
//             }
//         }
//      return ok ? sum :-1;
//     }
// };


class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }

        int ANS=INT_MAX;
        bool found=false;

        for(auto & it:mp)
        {
            vector<int> &ans=it.second;
            if(ans.size()<3)continue;
            for(int i=0;i+2<ans.size();i++)
            {
                found=true;
                int a=ans[i];
                int b=ans[i+1];
                int c=ans[i+2];

                int dist=2*(c-a);
                ANS=min(ANS,dist);
            }
        }
    return found ? ANS : -1;
    }
 };