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

// bool mirror(TreeNode* leftptr ,TreeNode * rightptr)
// {
//         if(leftptr==nullptr  && rightptr==nullptr)
//         {
//             return true;
//         }

//         if(leftptr==nullptr || rightptr==nullptr || leftptr->val !=rightptr->val)
//         {
//             return false;
//         }
//         return mirror(leftptr->left , rightptr->right) && mirror(leftptr->right,rightptr->left);
        
//     }
//     bool isSymmetric(TreeNode* root) {
//         if(root==nullptr)
//         {
//             return true;
//         }

//         return mirror(root->left,root->right);
//     }
// };





class Solution {
public:
bool isSymmetric(TreeNode* root) {

    if(root==nullptr)
    {
        return true;
    }
    stack<TreeNode*>s1,s2;
    s1.push(root->left);
    s2.push(root->right);
    while(!s1.empty() && !s2.empty())
    {
        TreeNode* node1=s1.top();
        TreeNode* node2=s2.top();
        s1.pop();
        s2.pop();

        if(node1==nullptr && node2==nullptr)
        {
            continue;
        }
        if(node1==nullptr || node2==nullptr || node1->val != node2->val)
        {
            return false;
        }

        s1.push(node1->left);
        s2.push(node2->right);

        s1.push(node1->right);
        s2.push(node2->left);
    }
    return s1.empty() && s2.empty();
    }
};