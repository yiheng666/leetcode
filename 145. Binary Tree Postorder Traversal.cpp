class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        stack<TreeNode*> st;
        vector<int> res;
        st.push(root);
        while (!st.empty()){
            TreeNode* p = st.top();
            st.pop();
            res.push_back(p->val);
            if (p->left) st.push(p->left);
            if (p->right) st.push(p->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};