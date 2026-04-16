

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]].push_back(i);
        }

        vector<int> result;

        for (int q : queries) {
            auto& indices = pos[nums[q]];

            if (indices.size() == 1) {
                result.push_back(-1);
                continue;
            }

            auto it = lower_bound(indices.begin(), indices.end(), q);
            int idx = it - indices.begin();

            int ans = INT_MAX;

            // Check current (if not same index)
            if (idx < indices.size() && indices[idx] != q) {
                int d = abs(q - indices[idx]);
                ans = min(ans, min(d, n - d));
            }

            // Check next
            if (idx + 1 < indices.size()) {
                int j = indices[idx + 1];
                int d = abs(q - j);
                ans = min(ans, min(d, n - d));
            }

            // Check previous
            if (idx - 1 >= 0) {
                int j = indices[idx - 1];
                int d = abs(q - j);
                ans = min(ans, min(d, n - d));
            }

            // Wrap-around checks
            int j = indices[0];
            if (j != q) {
                int d = abs(q - j);
                ans = min(ans, min(d, n - d));
            }

            j = indices.back();
            if (j != q) {
                int d = abs(q - j);
                ans = min(ans, min(d, n - d));
            }

            result.push_back(ans);
        }

        return result;
    }
};