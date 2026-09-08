// class Solution {
// public:
//     int countCommas(int n) {
//         string ans=to_string(n);
//         int size=ans.size();
//         if(size<4)
//         {
//             return 0;
//         }
//         string ans1="";
        
//         for(int i=1;i<ans.size();i++)
//            {
//             ans1+=ans[i];
//            } 
        
//         return stoi(ans1)+1;
        
//     }
// };

class Solution {
public:
    int countCommas(int n) {
        int count=0;
        for(int i=1000;i<=n;i++)
        {
            int x=i;
            while(x>=1000)
            {
                count++;
                x=x%1000;
            }
        }
        return  count;
    }
};