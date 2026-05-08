// class Solution {
// public:
//     int minJumps(vector<int>& nums) {
        
//     }
// };

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;

        int maxVal = *max_element(nums.begin(), nums.end());

        vector<int> spf(maxVal + 1);
        iota(spf.begin(), spf.end(), 0);
        if (maxVal >= 1) spf[1] = 1;

        for (int i = 2; 1LL * i * i <= maxVal; i++) {
            if (spf[i] == i) {
                for (long long j = 1LL * i * i; j <= maxVal; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }

        auto isPrime = [&](int x) {
            return x >= 2 && spf[x] == x;
        };

        auto getPrimeFactors = [&](int x) {
            vector<int> factors;
            while (x > 1) {
                int p = spf[x];
                factors.push_back(p);
                while (x % p == 0) x /= p;
            }
            return factors;
        };

        unordered_map<int, vector<int>> divisible;

        for (int i = 0; i < n; i++) {
            for (int p : getPrimeFactors(nums[i])) {
                divisible[p].push_back(i);
            }
        }

        vector<int> dist(n, -1);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (i == n - 1) return dist[i];

            for (int nei : {i - 1, i + 1}) {
                if (nei >= 0 && nei < n && dist[nei] == -1) {
                    dist[nei] = dist[i] + 1;
                    q.push(nei);
                }
            }

            int x = nums[i];

            if (isPrime(x) && divisible.count(x)) {
                for (int nei : divisible[x]) {
                    if (nei != i && dist[nei] == -1) {
                        dist[nei] = dist[i] + 1;
                        q.push(nei);
                    }
                }

                divisible.erase(x); // process this teleport group only once
            }
        }

        return dist[n - 1];
    }
};