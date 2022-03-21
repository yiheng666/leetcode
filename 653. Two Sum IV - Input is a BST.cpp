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
    vector<int> res;
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int left = 0,right = res.size() - 1;
        while (left < right){
            int sum = res[left] + res[right];
            if (sum == k) return true;
            else if (sum > k) right--;
            else left++;
        }
        return false;
    }
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        res.push_back(root->val);
        inorder(root->right);
    }
};