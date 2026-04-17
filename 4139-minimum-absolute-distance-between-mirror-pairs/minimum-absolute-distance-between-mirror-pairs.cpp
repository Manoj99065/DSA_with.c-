#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int minDist = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int rev = reverseNum(nums[i]);

            if (mp.count(nums[i])) {
                minDist = min(minDist, i - mp[nums[i]]);
            }

            mp[rev] = i;  // store reversed value
        }

        return minDist == INT_MAX ? -1 : minDist;
    }
};