class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int size=nums.size();
        sort(nums.begin(),nums.end());
        int curr=nums[0];
        vector<int>ans;
        for(int i=0;i<size;i++)
        {
            while(curr<nums[i])
            {
              ans.push_back(curr);
              curr++;
            }

            curr++;
        }
        return ans;
        
    }
};