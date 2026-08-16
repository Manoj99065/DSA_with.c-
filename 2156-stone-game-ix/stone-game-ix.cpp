class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int x : stones) {
            cnt[x % 3]++;
        }
        
        // If there are no stones with remainder 1 or 2, 
        // every move makes the sum divisible by 3 → Alice loses.
        if (cnt[1] == 0 && cnt[2] == 0) return false;
        
        // If the number of multiples of 3 is even,
        // Alice can win only if both remainder types exist.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        } 
        // If the number of multiples of 3 is odd,
        // Alice wins if the difference between counts of 1 and 2 is > 2.
        else {
            return abs(cnt[1] - cnt[2]) > 2;
        }
    }
};