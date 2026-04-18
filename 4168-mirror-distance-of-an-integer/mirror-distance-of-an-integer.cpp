class Solution {
public:
    int mirrorDistance(int n) {
        int j=n;
        int s=0;
        while(j>0)
        {
            int k=j%10;
            s=(s*10)+k;
            j=j/10;
        }
        int result=n-s;
        return abs(result);
        
    }
};