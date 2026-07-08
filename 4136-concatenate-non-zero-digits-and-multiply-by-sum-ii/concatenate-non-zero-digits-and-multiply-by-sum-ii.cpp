// class Solution {
// public:
//     vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
//         const long long MOD = 1e9 + 7;
//         vector<int>ans;
//         int size=queries.size();
//         for(int i=0;i<size;i++)
//         {
//             long long number=0;
//             string result="";
//             int sum=0;


//             int l = queries[i][0];
//             int r = queries[i][1];

//             for(int j=l;j<=r;j++)
//             {
//                 if(s[j]!='0')
//                 {
//                     number = (number * 10 + (s[j] - '0')) % MOD;
//                 }
//                 sum+=(s[j]-'0');
//             }
//             // long long  val=number*sum;
//             // ans.push_back(number * sum);
//             long long val = (number % MOD) * (sum % MOD) % MOD;
//             ans.push_back((int)val);
//         }
//     return ans;
//     }
// };



class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        const long long MOD = 1e9 + 7;

        vector<int> pos;
        vector<int> digit;

        // Store non-zero digits and their positions
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '0') {
                pos.push_back(i);
                digit.push_back(s[i]-'0');
            }
        }

        int n = digit.size();

        // prefix number
        vector<long long> pref(n+1,0);

        // prefix digit sum
        vector<long long> sum(n+1,0);

        vector<long long> pow10(n+1,1);


        for(int i=0;i<n;i++) {

            pref[i+1] = (pref[i]*10 + digit[i]) % MOD;

            sum[i+1] = sum[i] + digit[i];

            pow10[i+1] = (pow10[i]*10)%MOD;
        }


        vector<int> ans;


        for(auto &q: queries) {

            int l=q[0];
            int r=q[1];


            // first non zero >= l
            int left = lower_bound(pos.begin(),pos.end(),l)-pos.begin();


            // first non zero > r
            int right = upper_bound(pos.begin(),pos.end(),r)-pos.begin();


            // no non-zero digit
            if(left==right) {
                ans.push_back(0);
                continue;
            }


            // number of digits in this range
            int len = right-left;


            // extract number
            long long x = 
            (pref[right] - (pref[left]*pow10[len])%MOD + MOD)%MOD;


            long long digitSum = sum[right]-sum[left];


            long long result = (x * (digitSum%MOD))%MOD;


            ans.push_back(result);
        }


        return ans;
    }
};