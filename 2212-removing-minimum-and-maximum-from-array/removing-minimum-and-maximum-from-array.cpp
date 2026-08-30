class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        // Find indices of minimum and maximum elements
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        
        // Three possible strategies:
        // 1. Delete from left only
        int left = max(minIdx, maxIdx) + 1;
        
        // 2. Delete from right only
        int right = n - min(minIdx, maxIdx);
        
        // 3. Delete from both sides
        int both = min(minIdx, maxIdx) + 1 + (n - max(minIdx, maxIdx));
        
        return min({left, right, both});
    }
};