
// class Solution {
//     private:
//     int height(TreeNode* root)
//     {
//         if(root==nullptr)
//         {
//             return true;
//         }
//         int op1=height(root->left);
//         int op2=height(root->right);
//         int ans(max(op1,op2)+1);
//         return ans;
//     }


// public:
//     bool isBalanced(TreeNode* root) {
//         if(root==nullptr)
//         {
//             return true;
//         }
//             bool left=isBalanced(root->left);
//             bool right=isBalanced(root->right);
//             bool ans= abs(height(root->left)-height(root->right))<=1;
//             if(left && right && ans)
//             {
//                 return true;
//             }    
//         return false;   
//     }
// };


class Solution {
    private:
    pair<bool,int>isBalanc(TreeNode * root)
    {
        if(root==nullptr)
        {
            pair<bool,int>p=make_pair(true,0);
            return p;
        }

        pair<bool,int>left=isBalanc(root->left);
        pair<bool,int>right=isBalanc(root->right);

        bool leftans=left.first;
        bool rightans=right.first;
        bool diff=(abs(left.second-right.second))<=1;


        pair<bool,int>ans;
        ans.second=max(left.second,right.second)+1;

        if(leftans && rightans && diff)
        {
            ans.first=true;
        }
        else
        {
            ans.first=false;
        }
        return ans;
    }


    public:
    bool isBalanced(TreeNode* root) {
       return isBalanc(root).first;
    }
};