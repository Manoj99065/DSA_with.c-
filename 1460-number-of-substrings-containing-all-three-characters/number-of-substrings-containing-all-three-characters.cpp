// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int size=s.size();
//         int count=0;
//         for(int i=0;i<size;i++)
//         {
//             for( int j=i;j<size;j++)
//             {
//                 int I=0,J=0,K=0;
//                 for(int k=i;k<=j;k++)
//                 {
//                     if(s[k]=='a')
//                     {
//                         I=1;
//                     }
//                     if(s[k]=='b')
//                     {
//                         J=1;
//                     }
//                     if(s[k]=='c')
//                     {
//                         K=1;
//                     }
//                 }
//             if(I==1 && J==1 && K==1)
//             {
//              count++;
//             }
//             }
//         }

//       return count;  
//     }
// };

class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastA = -1, lastB = -1, lastC = -1;
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') lastA = i;
            if (s[i] == 'b') lastB = i;
            if (s[i] == 'c') lastC = i;

            if (lastA != -1 && lastB != -1 && lastC != -1) {
                count += 1 + min({lastA, lastB, lastC});
            }
        }

        return count;
    }
};