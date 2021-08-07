/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return traverse(root,p,q);
    }
    TreeNode* traverse(TreeNode* root,TreeNode* p,TreeNode* q){
        if (!root) return NULL;
        if (p == root || q == root) return root;

        TreeNode* Left =  traverse(root->left,p,q);
        TreeNode* Right = traverse(root->right,p,q);

        if (Left && Right) return root;
        if (Left == NULL && Right == NULL ) return NULL;
        return Left == NULL?  Right : Left;  

    }
};