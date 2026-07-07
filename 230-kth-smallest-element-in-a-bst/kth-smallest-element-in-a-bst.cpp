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
//     int kthSmallest(TreeNode* root, int k) {
//         queue<TreeNode*> qu;
//         qu.push(root);
//         vector<int> ans;
//         while(!qu.empty())
//         {
//             int size=qu.size();
//             for(int i=0;i<size;i++)
//             {
//                TreeNode * temp = qu.front();
//                ans.push_back(temp->val);
//                qu.pop();

//                if(temp->left)
//                {
//                    qu.push(temp->left);
//                }

//                if(temp->right)
//                 {
//                     qu.push(temp->right);
//                 }
//             }
//         }
//         sort(ans.begin(),ans.end());
//         return ans[k-1];   
//     }
// };


// class Solution {
// public:
//     int solve(TreeNode * root, int & k)
//     {
//         if(root==NULL)
//         {
//             return 0;
//         }
//         int left=solve(root->left,k);
//         if(left !=-1)
//         {
//            return left;
//         }
//         k--;
//        if(k==0)
//        {
//         return root->val;
//        }
//        return solve(root->right,k);
//     }


//     int kthSmallest(TreeNode* root, int k) { 
//         int ans=(root, k);
//         return ans;
//     }
// };


class Solution {
public:

    void solve(TreeNode* root, int &k, int &ans)
    {
        if(root == NULL)
        {
            return;
        }

        // Left subtree
        solve(root->left, k, ans);


        // Current node
        k--;

        if(k == 0)
        {
            ans = root->val;
            return;
        }

        // Right subtree
        solve(root->right, k, ans);
    }


    int kthSmallest(TreeNode* root, int k) 
    {
        int ans = -1;

        solve(root, k, ans);

        return ans;
    }
};