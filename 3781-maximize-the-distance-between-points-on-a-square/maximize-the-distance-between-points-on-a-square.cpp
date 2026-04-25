class Solution {
public:
bool check(vector<long long> &a ,int k,int side, long long d)
{
    int n=a.size();
    long long p=4LL*side;
    vector<long long> b=a;
    for(long long x : a)b.push_back(x+p);
    for(int s=0;s<n;s++)
    {
        int cnt=1,idx=s;
        long long last=b[s];


        while(cnt < k)
        {
            auto it =lower_bound(b.begin() +idx+1,
                                  b.begin()+s+n,
                                  last+d);

            
            if(it==b.begin()+s+n)break;
            idx=it-b.begin();
            last=*it;
            cnt++;
        }
        if(cnt==k &&  b[s]+p-last>=d)return true;
    }
    return false;
}
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long > arr;
        for(auto &p:points)
        {
            int x=p[0], y=p[1];
            if(y==0)arr.push_back(x);
            else if(x==side)arr.push_back(side+y);
            else if(y==side)arr.push_back(2LL * side+(side-x));
            else arr.push_back(3LL * side+(side-y));
        }


        // here we are doing sort of the given arr.
        sort(arr.begin(),arr.end());
        int l=0, h=side*2, ans=0;
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if( check(arr,k,side,mid))
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }

        }
        return ans;
    }
};