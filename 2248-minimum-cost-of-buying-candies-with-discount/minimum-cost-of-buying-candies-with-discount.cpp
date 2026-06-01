// class Solution {
// public:
//     int minimumCost(vector<int>& cost) {
        
//     }
// };


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) { // pay for first two in every group of 3
                ans += cost[i];
            }
        }

        return ans;
    }
};