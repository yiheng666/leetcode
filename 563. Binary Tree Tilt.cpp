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
    int res = 0;
    int findTilt(TreeNode* root) {
        if (root){
            res += (abs)(Sum(root->left) - Sum(root->right));
            findTilt(root->left);
            findTilt(root->right);
        }
        return res;
    }
    int Sum(TreeNode* root){
        if (!root) return 0;
        return Sum(root->left) + Sum(root->right) + root->val;
    }
};

class Solution {
public:
    int findTilt(TreeNode* root) {
        if (!root) return 0;
        return findTilt(root->left) + findTilt(root->right) + (abs)(Sum(root->left) - Sum(root->right));
    }
    int Sum(TreeNode* root){
        if (!root) return 0;
        return Sum(root->left) + Sum(root->right) + root->val;
    }
};