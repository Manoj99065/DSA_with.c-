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
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector<vector<int>>ans;
//         queue<TreeNode*>qu;
//         if(root==nullptr)
//         {
//             return ans;
//         }
       
//         qu.push(root);
//         while(!qu.empty())
//         {
//             int n=qu.size();
//             vector<int>level;
//             for(int i=0;i<n;i++)
//             {
//                 TreeNode* root1=qu.front();
//                 qu.pop();

//                level.push_back(root1->val);

//                if(root1->left)qu.push(root1->left);
//                if(root1->right)qu.push(root1->right); 
//             }
//             ans.push_back(level);
//         } 
//         return ans;       
//     }
// };

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
         vector<vector<int>> ans ;
         if(root == NULL)
    return {};
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            while(size--){
                
                TreeNode* n=q.front();
                q.pop();
                temp.push_back(n->val);
                   if(n->left) q.push(n->left);
if(n->right) q.push(n->right);
              
            }
            ans.push_back(temp);
            

           
        }
        return ans ;
        
    }
};