// class Solution {
// public:
//     int maxFrequencyElements(vector<int>& nums) {
//         map<int ,int>mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]++;
//         }

//         int val=INT_MIN;
        

//         for(auto i:mp)
//         {
//             val=max(val,i.second);
//         }

//         int ans=0; 
//         for(auto i:mp)
//         {
//             if(i.second ==val)
//             {
//                 ans=ans+val;
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        //precompute
map<int ,int >mpp;

for(int i=0; i<nums.size(); i++){
    mpp[nums[i]]++;
}

int maxfreq = 0;

for(auto it : mpp){
    if(it.second > maxfreq){
        maxfreq = it.second;
    }
}

int ans = 0;

for(auto it : mpp){
    if(it.second == maxfreq){
        ans += it.second;
    }
}

return ans;
        
        
    }
};
