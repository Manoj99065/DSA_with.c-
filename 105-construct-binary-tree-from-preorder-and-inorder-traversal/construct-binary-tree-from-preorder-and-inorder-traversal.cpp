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
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int size1=preorder.size();
//         int size2=inorder.size();
//         int idx=0;
        
//         TreeNode * root=new TreeNode(preorder[i]);
//         int start=0;
//         int end=inorder.size()-1;
//         while(idx<size1)
//         {
//             int i=0;
//             while(preorder[idx] != inorder[i])
//             {
//                i++; 
//             }
//             idx++;
//             root->left(start,i-1);
//             root->right(i+1,end);
            
//         }
//     return root;  
//     }
// };


class Solution {
    private :
    TreeNode* construct(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx)
    {
      if(start>end)
      {
        return NULL;
      }
      int rootval=preorder[idx];
      int i=start;
      for(;i<end;i++)
      {
        if(inorder[i]==rootval)
        {
            break;
        }
      }
        idx++;
        TreeNode * root=new TreeNode(rootval);
        root->left=construct(preorder,inorder,start,i-1,idx);
        root->right=construct(preorder,inorder,i+1,end,idx);
      
      return root;
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int idx=0;

        return construct(preorder,inorder,0,n-1,idx);
    }
};