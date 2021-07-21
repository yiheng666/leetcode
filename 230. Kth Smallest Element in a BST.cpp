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
    int ans = 0,sum = 0;
    int kthSmallest(TreeNode* root, int k) {
        kth(root,k);
        return ans;
    }
    void kth(TreeNode* root,int k){
        if (!root) return;
        kth(root->left,k);
        sum++;
        if (sum == k){
            ans = root->val;
            return;
        }
        kth(root->right,k);
    }
};