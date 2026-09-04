// class Solution {
// public:
//     int count=0;
//     string longestPalindrome(string s) {
//         // int left=0;
//         string ans="";
//         for(int right=0;right<s.length();right++)
//         {
//             string t="";
//             for(int j=right;j<s.length();j++)
//             {
//             t+=s[j]; 
//             string k=t;
//             reverse(k.begin(),k.end());
//             if(k==t)
//             {
//                 if(k.length()>count)
//                 {
//                     count=k.length();
//                    ans=k;
//                 }
//             } 
//             }
            
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            int l = i;
            int r = i;

            while(l >= 0 && r < s.length() && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }

                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while(l >= 0 && r < s.length() && s[l] == s[r]) {
                if(r - l + 1 > maxLen) {
                    start = l;
                    maxLen = r - l + 1;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};