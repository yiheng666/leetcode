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
    map<int,int> mp;
    int findSecondMinimumValue(TreeNode* root) {
        preorder(root);
        if (mp.size() <= 1) return -1;
        auto it = mp.begin();
        it++;
        return it->first;
    }
    void preorder(TreeNode* root){
        if (!root) return;
        mp[root->val]++;
        preorder(root->left);
        preorder(root->right);
    }
};