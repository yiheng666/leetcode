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
    int maxSum = 0;
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return maxSum;
    }
    vector<int> traverse(TreeNode* root){
        if (!root){
            return {1,INT_MAX,INT_MIN,0};
        }
        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);

        vector<int> res(4);
        if (left[0] == 1 && right[0] == 1 && left[2] < root->val && right[1] > root->val){
            res[0] = 1;
            res[1] = min(left[1],root->val);
            res[2] = max(right[2],root->val);
            res[3] = left[3] + right[3] + root->val;
            maxSum = max(maxSum,res[3]);
        }
        else{
            res[0] = 0;
        }
        return res;
    }
};