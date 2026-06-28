class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1)
        {
            arr[0]=1;
        }
        long long  i=1;
        while(i<arr.size())
        {
            if(arr[i]-arr[i-1]<=1)
            {
              i++;
            }
            else
            {
                arr[i]=arr[i-1]+1;
            }
        }
        return *max_element(arr.begin(),arr.end());
    }
};