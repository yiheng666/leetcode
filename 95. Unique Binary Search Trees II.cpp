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
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
    vector<TreeNode*> generate(int low,int high){
        vector<TreeNode*> ans;
        if (low > high){
            ans.push_back(nullptr);
            return ans;
        }
        for (int i=low;i<=high;i++){
            vector<TreeNode*> leftTree = generate(low,i-1);
            vector<TreeNode*> rightTree = generate(i+1,high);
            for (TreeNode* left : leftTree){
                for (TreeNode* right : rightTree){
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};