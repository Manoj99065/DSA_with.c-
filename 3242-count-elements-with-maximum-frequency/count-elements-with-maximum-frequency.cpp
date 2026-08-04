class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int ,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        int val=INT_MIN;
        

        for(auto i:mp)
        {
            val=max(val,i.second);
        }

        int ans=0; 
        for(auto i:mp)
        {
            if(i.second ==val)
            {
                ans=ans+val;
            }
        }

        return ans;
    }
};