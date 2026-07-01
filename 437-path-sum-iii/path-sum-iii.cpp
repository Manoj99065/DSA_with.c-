/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
  
class Solution {
  public:
    void solve(TreeNode* root, int k , vector<int> &ans, int &count)
    {
        if(root==NULL)
        {
            return ;
        }
    ans.push_back(root->val);
    
    solve(root->left,k,ans,count);
    solve(root->right,k,ans,count);
    
    int size=ans.size();
    long long sum=0;
    for(int i=size-1;i>=0;i--)
    {
        sum=sum+ans[i];
        if(sum==k)
        {
            count++;
        }
    }

    ans.pop_back();
}
    int pathSum(TreeNode *root, int k) {
        // code here
        
        vector<int>ans;
        int count=0;
        solve(root,k,ans,count);
        return count;
        
        
        
    }
};