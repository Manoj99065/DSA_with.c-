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
private:
 void solve(TreeNode* root, int level, vector<vector<int>> & levels)
 {
    if(root==NULL)
    {
        return ;
    }
    if(levels.size()==level)
    {
        levels.push_back({});
    }
    levels[level].push_back(root->val);
    solve(root->left,level+1,levels);
    solve(root->right,level+1,levels);
 }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        vector<vector<int>> levels;
        solve(root,0,levels);

        for(int i=0;i<levels.size();i++)
        {
            if(i%2==1)
            {
                reverse(levels[i].begin(),levels[i].end());
            }    
        }
     return levels;   
    }
};