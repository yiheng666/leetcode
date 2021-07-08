class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left && right) ? min(left,right)+1 : left+right+1;
    }
};