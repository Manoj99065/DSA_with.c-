// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(root==NULL)
//         {
//             return NULL;
//         }
//         if(root==p || root==q)
//         {
//             return root;
//         }

//         TreeNode * leftAns=lowestCommonAncestor(root->left,p,q);
//         TreeNode * rightAns=lowestCommonAncestor(root->right,p,q);


//         if(leftAns!=NULL && rightAns!=NULL)
//         {
//             return root;
//         }

//         else if(leftAns!=NULL && rightAns==NULL)
//         {
//             return leftAns;
//         }

//         else if(rightAns!=NULL && leftAns==NULL)
//         {
//             return rightAns;
//         }

//         else 
//         {
//             return NULL;
//         }
        
//     }
// };

// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (!root || root == p || root == q)
//             return root;
        
//         TreeNode* lca_from_left = lowestCommonAncestor(root->left, p, q);
//         TreeNode* lca_from_right = lowestCommonAncestor(root->right, p, q);
//         if (lca_from_left && lca_from_right)
//             return root;

//         return lca_from_left ? lca_from_left : lca_from_right;
//     }
// };

class Solution
{
    public:

bool findPath(TreeNode* root, vector<TreeNode*>& path, TreeNode * n) {
    if (root == nullptr) return false;

    // Store current node
    path.push_back(root);

    if (root == n || findPath(root->left, path, n) || findPath(root->right, path, n)) {
        return true;
    }

    // remove root from path and return false
    path.pop_back();
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
    vector<TreeNode*> path1, path2;

    // Find paths from root to n1 
    // and root to n2
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2)) return nullptr;

    // Compare the paths to get 
    // the first different value
    int i = 0;
    for (i = 0; i < path1.size() && i < path2.size(); i++) {
        if (path1[i] != path2[i]) return path1[i - 1];
    }
    return path1[i - 1];
}
};