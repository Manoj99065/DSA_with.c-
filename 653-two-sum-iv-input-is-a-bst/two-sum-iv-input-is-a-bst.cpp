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

//     void inorder(TreeNode * root, vector<int> & inorderval)
//     {
//         if(root == NULL)
//         {
//             return;
//         }
//         inorder(root->left,inorderval);
//         inorderval.push_back(root->val);
//         inorder(root->right,inorderval);
//     }
//     bool findTarget(TreeNode* root, int k) {
//         vector<int>inorderval;

//         inorder(root,inorderval);
        

//         int i=0;
//         int j=inorderval.size()-1;
//         cout<<j;
//         int t=j;
//         while(i<j)
//         {
//             int sum=0;
//             if(i==j)
//             {
//             sum=inorderval[i];
//             }
//             else
//             {
//             sum=inorderval[i]+inorderval[j];
//             }
//             cout<<sum;
//             if(sum==k)
//             {
//                 return true;
//             }
//             if(sum < k)
//             {
//                 i++;
//             }
//             else
//             {
//                 j--;
//             }
//         }
//       return false;  
//     }
// };




class Solution {
public:

    unordered_set<int> st;

    bool findTarget(TreeNode* root, int k) {

        if ( root ==NULL){
            return false;
        }

        if( st.count(k- root->val)){
            return true;
        }

        st.insert(root->val);

        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};
