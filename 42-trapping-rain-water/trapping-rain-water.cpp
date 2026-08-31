// class Solution {
// public:
//     int trap(vector<int>& height) {
//        int size=height.size();

//        vector<int>leftarr(size,0);
//        vector<int>rightarr(size,0);


//        leftarr[0]=height[0];
//        rightarr[size-1]=height[size-1];


//        for(int i=1;i<size;i++)
//        {
//         leftarr[i]=max(leftarr[i-1],height[i]);
//        }



//        for(int i=size-2;i>=0;i--)
//        {
//         rightarr[i]=max(rightarr[i+1],height[i]);
//        }

//         // here we are implement some code.
//         int ans=0;
//         for(int i=0;i<size;i++)
//         {
//             ans+=min(leftarr[i],rightarr[i])-height[i];
//         }
//         return ans;
//     }
// };










class Solution {
public:
    int trap(vector<int>& height) {
    int size=height.size();
    int lmax=0;
    int rmax=0;
    int left=0, right=size-1;
    int ans=0;
    while(left<=right)
    {
        lmax=max(height[left],lmax);
        rmax=max(height[right],rmax);

        if(lmax<rmax)
        {
            ans+=lmax-height[left];
            left++;
        }
        else
        {
            ans+=rmax-height[right];
            right--;
        }
    }
    return ans;
    }
};