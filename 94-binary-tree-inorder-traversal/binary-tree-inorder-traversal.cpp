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
    void IOT(TreeNode * root,vector<int> & ans)
    {
       if(root== NULL)
       {
        return ;
       }
       // this is the left portion.
       
       IOT(root->left,ans);
       ans.push_back(root->val);

       // This is the right portion of the recursion.    
       IOT(root->right,ans);


    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        IOT(root, ans);
        return ans;
        
    }
};