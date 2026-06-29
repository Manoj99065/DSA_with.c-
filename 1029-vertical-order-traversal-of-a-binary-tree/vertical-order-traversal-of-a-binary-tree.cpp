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
        map<int,map<int,vector<int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>qu;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }

        qu.push(make_pair(root,make_pair(0,0)));
        while(!qu.empty())
        {
            pair<TreeNode*,pair<int,int>>temp=qu.front();
            qu.pop();
            TreeNode * firstNode=temp.first;
            int hd=temp.second.first;
            int level=temp.second.second;
            nodes[hd][level].push_back(firstNode->val);

            if(firstNode->left)
            {
                qu.push(make_pair(firstNode->left,make_pair(hd-1,level+1)));
            }
             if(firstNode->right)
            {
                qu.push(make_pair(firstNode->right,make_pair(hd+1,level+1)));
            }
        }

         for(auto i:nodes)
        {
            vector<int>col;
            for(auto j:i.second)
            {
                sort(j.second.begin(), j.second.end());
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

//  map<int , map<int, multiset<int>>> nodes;
//         queue<pair<TreeNode*, pair<int,int>>> qu;
//         vector<vector<int>> ans;
//         if(root == NULL) return ans;

//         qu.push(make_pair(root,make_pair(0,0)));

//         while(!qu.empty())
//         {
//             pair<TreeNode*,pair<int,int>> temp=qu.front();
//             qu.pop();
//             TreeNode* frontNode=temp.first;
//             int hd=temp.second.first;
//             int lvl=temp.second.second;


//             nodes[hd][lvl].insert(frontNode->val);
//             if(frontNode->left)
//             {
//                 qu.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
//             }
//             if(frontNode->right)
//             {
//                 qu.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
//             }
//         }

//         for(auto i: nodes)
//         {
//             vector<int>col;
//             for(auto j: i.second)
//             {
//                 for(auto k:j.second)
//                 {
//                     col.push_back(k);
//                 }
//             }
//             ans.push_back(col);
//         }
//         return ans; 