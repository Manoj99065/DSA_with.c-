class Solution {
public:
    bool checkDivisibility(int n) {
        int t=n;
         int sum =0;
         int mul=1;
         while(t>=1)
         {
            int k=t%10;
            sum=sum+k;
            mul=mul*k;

            // here we are apply some anther thing oky.
            t=t/10;
         }
         
         int div=sum+mul;
         cout<<div;
         if(n % div == 0)
         {
            return true;
         }
         return false;


    }
};