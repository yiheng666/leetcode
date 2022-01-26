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
class Solution {
public:
    TreeNode *node1,*node2,*pre;
    void recoverTree(TreeNode* root) {
        inorder(root);
        int temp = node1->val;
        node1->val = node2->val;
        node2->val = temp;
    }
    void inorder(TreeNode* root){
        if (root == NULL) return;
        inorder(root->left);
        if (pre != NULL && pre->val > root->val){
            if (node1 == NULL) node1 = pre;
            node2 = root;
        }
        pre = root;
        inorder(root->right);
    }
};