// class Solution {
// public:
//     int numOfStrings(vector<string>& patterns, string word) {
//         int size=patterns.size();
//         int count=0;
//         for(int i=0;i<size;i++)
//         {
//            if(word.contains(patterns[i]))
//             {
//                 count++;
//             }
//             else
//             {
//                 continue;
//             }
//         } 
//         return count;       
//     }
// };

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int count = 0;

        for(int i = 0; i < n; i++) {
            string pat = patterns[i];
            int m = word.size();
            int k = pat.size();

            bool found = false;

            // manual substring check
            for(int j = 0; j <= m - k; j++) {
                int l = 0;

                while(l < k && word[j + l] == pat[l]) {
                    l++;
                }

                if(l == k) {
                    found = true;
                    break;
                }
            }

            if(found) {
                count++;
            }
        }

        return count;
    }
};