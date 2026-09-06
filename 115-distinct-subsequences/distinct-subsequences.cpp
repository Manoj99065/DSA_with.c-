// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         vector<int>v(26,0);
//         int count=1;
//         for(int i=0;i<s.length();i++)
//         {
//             int j=s[i]-'a';
//             v[j]++;
//         }
//         for(int i=0;i<t.length();i++)
//         {
//             int j=t[i]-'a';
//             v[j]--;
//         }

//         for(int i=0;i<v.size();i++)
//         {
//             if(v[i]>=1)
//             {
//                 count=count+v[i];
//             }
//         }
// return count;

        
//     }
// };   


class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned long long>dp(t.length()+1,0);
        dp[0]=1;
        for(int i=0;i<s.length();i++)
        {
            for(int j=t.length()-1;j>=0;j--)
            {
                if(s[i]==t[j])
                {
                    dp[j+1]+=dp[j];
                }
            }
        }
        return dp[t.length()];
    }
};