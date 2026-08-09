class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = sum of piles[i ... n-1]
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][m] = maximum stones the current player
        // can get starting from index i with M = m
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int m = n; m >= 1; m--) {

                // Can take all remaining piles
                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                    continue;
                }

                for (int x = 1; x <= 2 * m; x++) {
                    int nextM = max(m, x);

                    // Total remaining stones - opponent's best result
                    dp[i][m] = max(
                        dp[i][m],
                        suffix[i] - dp[i + x][nextM]
                    );
                }
            }
        }

        return dp[0][1];
    }
};