class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = index in word1 where word2[j] can be matched,
        // while matching word2[j...m-1] from right to left.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;

        // We can use at most one mismatch.
        bool changed = true;

        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Case 1: exact match
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Case 2: use this position as the one mismatch
            else if (changed &&
                     (j == m - 1 || i < last[j + 1])) {

                ans.push_back(i);
                j++;

                changed = false;
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};