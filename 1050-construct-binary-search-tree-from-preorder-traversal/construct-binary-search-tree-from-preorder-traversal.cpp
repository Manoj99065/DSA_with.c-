class Solution {


private:
    TreeNode* build(vector<int>& preorder, int minVal, int maxVal, int& i) {
        if (i >= preorder.size()) return nullptr;

        int val = preorder[i];

        if (val < minVal || val > maxVal) return nullptr;

        TreeNode* root = new TreeNode(val);
        i++;

        root->left = build(preorder, minVal, val, i);
        root->right = build(preorder, val, maxVal, i);

        return root;
    }
    public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, INT_MIN, INT_MAX, i);
    }
};