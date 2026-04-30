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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr)
        {
            return {};
        }
        vector<int>ans;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty())
        {
            TreeNode* val1=NULL;
            int size=qu.size();
            while(size--)
            {
                val1=qu.front();
                qu.pop();
                if(val1->left!=nullptr)qu.push(val1->left);
                if(val1->right!=nullptr)qu.push(val1->right);
               
            }
            ans.push_back(val1->val);
        } 
        return ans;       
    }
};