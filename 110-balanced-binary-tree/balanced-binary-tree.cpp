
class Solution {
    private:
    int height(TreeNode* root)
    {
        if(root==nullptr)
        {
            return true;
        }
        int op1=height(root->left);
        int op2=height(root->right);
        int ans(max(op1,op2)+1);
        return ans;
    }


public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
        {
            return true;
        }
            bool left=isBalanced(root->left);
            bool right=isBalanced(root->right);
            bool ans= abs(height(root->left)-height(root->right))<=1;
            if(left && right && ans)
            {
                return true;
            }    
        return false;   
    }
};