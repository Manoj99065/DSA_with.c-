// class Solution {
// public:
//     string mapWordWeights(vector<string>& words, vector<int>& weights) {
        
//     }

// };
class Solution {
public:
    string  mapWordWeights(vector<string>& words, vector<int>& weights) {
        string result;

        for (const string& word : words) {
            long long sum = 0;

            for (char ch : word) {
                sum += weights[ch - 'a'];
            }

            int modVal = sum % 26;

            // Reverse alphabetical mapping:
            // 0 -> 'z', 1 -> 'y', ..., 25 -> 'a'
            result.push_back(char('z' - modVal));
        }

        return result;
    }
};