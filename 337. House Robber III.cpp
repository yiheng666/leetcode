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
    unordered_map<TreeNode *,int> memo;
    int rob(TreeNode* root) {
        if (!root)
            return 0;
        if (memo.count(root))
            return memo[root];
        int do_it = root->val
                + ((root->left == nullptr) ? 0 : rob(root->left->left) + rob( root->left->right) )
                + ((root->right == nullptr) ? 0 : rob(root->right->left) + rob( root->right->right) );
        int not_do = rob(root->left) + rob(root->right);
        int ans = max(do_it,not_do);
        memo[root] = ans;
        return ans; 
    }
};