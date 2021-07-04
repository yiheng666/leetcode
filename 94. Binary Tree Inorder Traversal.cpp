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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        auto p = root;
        while (p || !st.empty()){
            if (p){
                st.push(p);
                p = p->left;
            }
            else{
                auto node = st.top();
                st.pop();
                ans.push_back(node->val);
                p = node->right;
            }
        }
        return ans;
    }
};