class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result=0;
        int sum=0;
        for(int i=0;i<gain.size();i++)
        {
            sum=sum+gain[i];
            if(sum>result)
            {
                result=sum;
            }
        }
       return result; 
    }
};