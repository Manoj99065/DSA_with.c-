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

    void POT(TreeNode * root, vector <int> &ans)
    {
        if(root==NULL)
        {
            return ;
        }
        ans.push_back(root->val);
        POT(root->left,ans);
        POT(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        POT(root,ans);
        return ans; 
    }
};