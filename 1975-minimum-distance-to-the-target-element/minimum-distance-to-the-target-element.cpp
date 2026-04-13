class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int result=INT_MAX;
        int left=0;
        int right=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target )
            {
                // if(i==0)
                result=min(result,abs(i-start));

            }
        }
            return result;
        }
};