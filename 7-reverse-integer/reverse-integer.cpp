// class Solution {
// public:
//     int reverse(int x) {
//        long long int   result=0;
//        int sign= x<0? -1 : 1;
      
//        x=abs(x);
//         while(x>0)
//         {

//             int val=(x%10);
//             // if(val=='-') break;
//             result=(result*10 )+(val);
//             x=x/10;
//         }

//         if (result > INT_MAX || result < INT_MIN)
//             return 0;
//         return sign * result;
//     }
// };


class Solution {
public:
    int reverse(int x) {
        long long result = 0;

        int sign = x < 0 ? -1 : 1;
        long long int X=x;
        X = abs(X);

        while (X> 0) {
            int val = X % 10;

            result = result * 10 + val;

            X = X / 10;
        }

        result *= sign;

        if (result > INT_MAX || result < INT_MIN)
            return 0;

        return (int)result;
    }
};