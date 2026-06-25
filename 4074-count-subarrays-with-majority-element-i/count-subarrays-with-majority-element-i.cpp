class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int size=nums.size();
        int count=0;
        for(int i=0;i<size;i++)
        {
            int cnt=0;
            for(int j=i;j<size;j++)
            {
                if(nums[j]==target)
                {
                    cnt++;
                }
            
                if(cnt>(j-i+1)/2) count++;
                
            }  
        }
      return count;  
    }
};