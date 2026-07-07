class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n);
        string ans="";
        int digit_sum=0;
        // cout<<typeid(s).name();
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
              continue;
            }
            ans=ans+s[i];
            digit_sum+=(s[i]-'0');
        }

        if (ans.empty()) {
            return 0;
        }
       long long  ans1=stoll(ans);
       long long result=ans1*digit_sum;
       return result;

    }
};