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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int , map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int,int>>> qu;
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        qu.push(make_pair(root,make_pair(0,0)));

        while(!qu.empty())
        {
            pair<TreeNode*,pair<int,int>> temp=qu.front();
            qu.pop();
            TreeNode* frontNode=temp.first;
            int hd=temp.second.first;
            int lvl=temp.second.second;


            nodes[hd][lvl].insert(frontNode->val);
            if(frontNode->left)
            {
                qu.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right)
            {
                qu.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }

        for(auto i: nodes)
        {
            vector<int>col;
            for(auto j: i.second)
            {
                for(auto k:j.second)
                {
                    col.push_back(k);
                }
            }
            ans.push_back(col);
        }
        return ans; 
    }
};