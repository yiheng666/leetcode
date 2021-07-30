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
    unordered_map<string,int> memo;
    vector<TreeNode*> ans;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string s = count(root);
        return ans;
    }
    string count(TreeNode* root){
        if (!root) return "#";
        string left,right,str; 
        left = count(root->left);
        right = count(root->right);
        str = left + "," + right + "," + to_string(root->val);
        if (memo[str] == 1){
            ans.push_back(root);
        }
        memo[str]++;
        return str;
    }
};