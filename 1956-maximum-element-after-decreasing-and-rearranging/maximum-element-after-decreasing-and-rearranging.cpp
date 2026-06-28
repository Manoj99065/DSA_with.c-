class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        if(arr[0]!=1)
        {
            arr[0]=1;
        }
        int ans=1;
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
            ans=max(ans,arr[i-1]);
        }
        // return *max_element(arr.begin(),arr.end());
        return ans;
    }
};


// class Solution {
// public:
//     int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
//         int n = arr.size();
//         vector<int> freq(n + 1,0);
//         for(int i =0;i<n;i++){
//             freq[min(arr[i],n)]++;
//         }
//         int ans = 0;
//         for(int i =1;i<=n;i++){
//             if(freq[i] == 0) continue;

//             ans = min(ans + freq[i],i);
//         }
//         return ans;
//     }
// };