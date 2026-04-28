// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int maxDepth(TreeNode * root)
//     {
//         if(root==nullptr)
//         {
//             return 0 ;
//         }
//         int left=maxDepth(root->left);
//         int right=maxDepth(root->right);
//         int ans=max(right,left)+1;
//         return ans;   
//     }
// };



class Solution {
public:
    int maxDepth(TreeNode * root)
    {
        if(root==nullptr)return 0;
        queue<TreeNode*> qu;
        qu.push(root);
        int depth=0;
        while(!qu.empty())
        {
            int size=qu.size();
           
            for(int i=0;i<size;i++)
            {
                TreeNode* node =qu.front();
                qu.pop();
             if(node->left) qu.push(node->left);
             if(node->right)qu.push(node->right);
            }
        depth++;
        }
        return depth;
    }
};