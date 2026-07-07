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
    int kthSmallest(TreeNode* root, int k) {
        queue<TreeNode*> qu;
        qu.push(root);
        vector<int> ans;
        while(!qu.empty())
        {
            int size=qu.size();
            for(int i=0;i<size;i++)
            {
               TreeNode * temp = qu.front();
               ans.push_back(temp->val);
               qu.pop();

               if(temp->left)
               {
                   qu.push(temp->left);
               }

               if(temp->right)
                {
                    qu.push(temp->right);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];   
    }
};