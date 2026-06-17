#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        vector<long long> len(n);
        
        long long cur = 0;
        const long long LIM = (long long)1e15 + 5;

        // Step 1: compute length after each operation
        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c >= 'a' && c <= 'z') {
                cur = min(LIM, cur + 1);
            }
            else if (c == '*') {
                if (cur > 0) cur--;
            }
            else if (c == '#') {
                cur = min(LIM, cur * 2);
            }
            // '%' does not change length

            len[i] = cur;
        }

        if (k >= cur) return '.';

        // Step 2: trace backwards
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long prevLen = (i > 0 ? len[i - 1] : 0);

            if (c >= 'a' && c <= 'z') {
                if (k == len[i] - 1) {
                    return c;
                }
                // else continue
            }
            else if (c == '*') {
                // '*' removed last char, nothing to map if k was last
                // otherwise unchanged
            }
            else if (c == '#') {
                // string was doubled
                if (k >= prevLen) {
                    k -= prevLen;
                }
            }
            else if (c == '%') {
                // reverse mapping
                k = prevLen - 1 - k;
            }
        }

        return '.';
    }
};